// -*- C++ -*-
/*!
 * @file  sound_outer.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "sound_outer.h"
#include "DxLib.h"
#include <string>

// Module specification
// <rtc-template block="module_spec">
static const char* sound_outer_spec[] =
  {
    "implementation_id", "sound_outer",
    "type_name",         "sound_outer",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "shirai",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.Sound_File", "hirate_uti.mp3",

    // Widget
    "conf.__widget__.Sound_File", "text",
    // Constraints

    "conf.__type__.Sound_File", "string",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
sound_outer::sound_outer(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_volume_percentageIn("volume_percentage", m_volume_percentage)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sound_outer::~sound_outer()
{
}



RTC::ReturnCode_t sound_outer::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("volume_percentage", m_volume_percentageIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("Sound_File", m_Sound_File, "hirate_uti.mp3");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sound_outer::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t sound_outer::onActivated(RTC::UniqueId ec_id)
{
	ChangeWindowMode(TRUE);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t sound_outer::onDeactivated(RTC::UniqueId ec_id)
{
	// 再生を止めます
	StopSoundMem(SHandle);

	// キー入力があるまで待ちます(『WaitKey』使用)
	//WaitKey();

	// サウンドハンドルの削除
	DeleteSoundMem(SHandle);

	DxLib_End();        // ＤＸライブラリ使用の終了処理


  return RTC::RTC_OK;
}


RTC::ReturnCode_t sound_outer::onExecute(RTC::UniqueId ec_id)
{
	if (m_volume_percentageIn.isNew())
	{
		m_volume_percentageIn.read();

		SetDoubleStartValidFlag(TRUE);

		DxLib_Init();

		// test.wavのメモリへの読み込みサウンドハンドルをSHandleに保存します


		SHandle = LoadSoundMem(m_Sound_File.c_str());

		// 音量の設定
		ChangeVolumeSoundMem(255 * m_volume_percentage.data, SHandle);

		// 読みこんだ音をループ再生します(『PlaySoundMem』関数使用)
		//PlaySoundMem(SHandle, DX_PLAYTYPE_NORMAL);
		PlaySoundMem(SHandle, DX_PLAYTYPE_BACK);

		// ５秒待つ『WaitTimer』使用
		//WaitTimer(0);
	}
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sound_outer::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sound_outer::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void sound_outerInit(RTC::Manager* manager)
  {
    coil::Properties profile(sound_outer_spec);
    manager->registerFactory(profile,
                             RTC::Create<sound_outer>,
                             RTC::Delete<sound_outer>);
  }
  
};


