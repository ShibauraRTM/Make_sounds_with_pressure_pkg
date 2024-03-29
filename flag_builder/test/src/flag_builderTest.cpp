﻿// -*- C++ -*-
/*!
 * @file  flag_builderTest.cpp
 * @brief calculate a inclination, convert a proportion and output a proportion. 
 * @date $Date$
 *
 * @author 白井哲平<shibaurartm@gmail.com>
 *
 * ありません
 *
 * $Id$
 */

#include "flag_builderTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* flag_builder_spec[] =
  {
    "implementation_id", "flag_builderTest",
    "type_name",         "flag_builderTest",
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
flag_builderTest::flag_builderTest(RTC::Manager* manager)
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
flag_builderTest::~flag_builderTest()
{
}



RTC::ReturnCode_t flag_builderTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("DataOut", m_DataOutIn);
  
  // Set OutPort buffer
  addOutPort("DataIn", m_DataInOut);
  
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
RTC::ReturnCode_t flag_builderTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t flag_builderTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t flag_builderTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*!
 * InPortの値がFlag(閾値)を越えた時、dt(コンフィギュレーション)秒に
 * おける値の上昇度(傾き)を求める。この上昇度を三角関数のtanとし、
 * sinに変換し0～1の値を出力する。
 */

RTC::ReturnCode_t flag_builderTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t flag_builderTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t flag_builderTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void flag_builderTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(flag_builder_spec);
    manager->registerFactory(profile,
                             RTC::Create<flag_builderTest>,
                             RTC::Delete<flag_builderTest>);
  }
  
};


