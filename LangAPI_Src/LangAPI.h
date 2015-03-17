//---------------------------------------------------------------------------
// Copyright (C) 2015 Krzysztof Grochocki
//
// This file is part of PluginAPI for AQQ IM
//
// PluginAPI for AQQ IM is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// PluginAPI for AQQ IM is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GNU Radio; see the file COPYING. If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street,
// Boston, MA 02110-1301, USA.
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#ifndef LangAPIH
#define LangAPIH
//---------------------------------------------------------------------------
#include "acSlider.hpp"
#include "sButton.hpp"
#include "sCheckBox.hpp"
#include "sColorSelect.hpp"
#include "sComboBox.hpp"
#include "sComboBoxes.hpp"
#include "sEdit.hpp"
#include "sGroupBox.hpp"
#include "sLabel.hpp"
#include "sListBox.hpp"
#include "sListView.hpp"
#include "sMaskEdit.hpp"
#include "sMemo.hpp"
#include "sPageControl.hpp"
#include "sPanel.hpp"
#include "sRadioButton.hpp"
#include "sSpeedButton.hpp"
#include "sSpinEdit.hpp"
#include "sStatusBar.hpp"
#include "sTrackBar.hpp"
#include <System.Actions.hpp>
#include <System.Classes.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
//---------------------------------------------------------------------------
typedef struct TLangCache
{
	UnicodeString StrID;
	UnicodeString StrEntry;
} TLangCache;
extern DynamicArray<TLangCache> LangCache;
extern UnicodeString LangPath;
void ClearLngCache();
UnicodeString GetLangStr(UnicodeString ID);
void LangForm(TForm* Form);
void LangFrame(TFrame Form);
//---------------------------------------------------------------------------
#endif
