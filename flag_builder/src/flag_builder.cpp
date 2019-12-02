// -*- C++ -*-
/*!
 * @file  flag_builder.cpp
 * @brief calculate a inclination, convert a proportion and output a proportion. 
 * @date $Date$
 *
 * @author 白井哲平<shibaurartm@gmail.com>
 *
 * ありません
 *
 * $Id$
 */

#include "flag_builder.h"

// Module specification
// <rtc-template block="module_spec">
static const char* flag_builder_spec[] =
  {
    "implementation_id", "flag_builder",
    "type_name",         "flag_builder",
    "description",       "calculate a inclination, convert a proportion and output a proportion. ",
    "version",           "1.0.0",
    "vendor",            "shirai",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.dt", "0.5",
    "conf.default.Flag", "5000",

    // Widget
    "conf.__widget__.dt", "text",
    "conf.__widget__.Flag", "text",
    // Constraints

    "conf.__type__.dt", "double",
    "conf.__type__.Flag", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
flag_builder::flag_builder(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_DataInIn("DataIn", m_DataIn),
    m_DataOutOut("DataOut", m_DataOut)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
flag_builder::~flag_builder()
{
}



RTC::ReturnCode_t flag_builder::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("DataIn", m_DataInIn);
  
  // Set OutPort buffer
  addOutPort("DataOut", m_DataOutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("dt", m_dt, "0.5");
  bindParameter("Flag", m_Flag, "5000");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builder::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t flag_builder::onActivated(RTC::UniqueId ec_id)
{
	flag = 0;
	y1 = 0.0;
	nowtime = 0.0;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builder::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*!
 * InPortの値がFlag(閾値)を越えた時、dt(コンフィギュレーション)秒に
 * おける値の上昇度(傾き)を求める。この上昇度を三角関数のtanとし、
 * sinに変換し0～1の値を出力する。
 */

RTC::ReturnCode_t flag_builder::onExecute(RTC::UniqueId ec_id)
{
	if (m_DataInIn.isNew()) {
		m_DataInIn.read();
		setTimestamp(m_DataIn);  //現在時刻を取得
		double nsec = (m_DataIn.tm.nsec);  //現在時刻の小数点以下10桁を取得(ナノ秒)
		double time = (m_DataIn.tm.sec % 10000) + (nsec / 1000000000);  //現在時刻と小数点以下の和

		if (m_DataIn.data > m_Flag) {

			if (flag == 1) {
				if (time > nowtime + m_dt) {  //最初に取得した時間からdt秒経過したら
					double dD = m_DataIn.data - y1; //圧力の差を計算
					double tan = (dD / 10) / m_dt; //tanを計算
					m_DataOut.data = sqrt(1 - (1 / ((tan*tan) + 1)));  //出力する値をSinで出力

					std::cout << "sin = " << m_DataOut.data << std::endl; //debag sinを出力

					m_DataOutOut.write();
					flag = -1;
				}
			}
			else if (flag == 0) {      //DataInがm_Flagを越え始めたとき
				y1 = m_DataIn.data;    //その瞬間のDataInの値をy1に保存する
				nowtime = time;        //その瞬間の時間（time）をnowtimeに保存する
				flag = 1;
			}

		}
		else {
			flag = 0;
		}
	}

  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builder::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builder::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void flag_builderInit(RTC::Manager* manager)
  {
    coil::Properties profile(flag_builder_spec);
    manager->registerFactory(profile,
                             RTC::Create<flag_builder>,
                             RTC::Delete<flag_builder>);
  }
  
};


