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
#pragma hdrstop
#include "LangAPI.h"
//---------------------------------------------------------------------------
DynamicArray<TLangCache> LangCache;
UnicodeString LangPath;
//---------------------------------------------------------------------------

void __fastcall ClearLngCache()
{
  LangCache.Length = 0;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall GetLangStr(UnicodeString ID)
{
  for(int stop = LangCache.Length - 1, count = 0; count <= stop; count++)
  {
    if(LangCache[count].StrID == ID)
	 return LangCache[count].StrEntry;
  }
  UnicodeString FileName = LangPath + "Const.lng";
  if(!FileExists(FileName)) return "";
  UnicodeString result;
  TStringList* LangFile = new TStringList;
  try
  {
	LangFile->LoadFromFile(FileName);
	for(int stop = LangFile->Count - 1, count = 0; count <= stop; count++)
    {
	  if(LangFile->Strings[count].Pos(ID + "=")==1)
	  {
		result = LangFile->Strings[count].Delete(1,ID.Length() + 1);
        break;
      }
    }
  }
  __finally
  {
    delete LangFile;
  }
  LangCache.Length = LangCache.Length + 1;
  LangCache[LangCache.Length - 1].StrID = ID;
  LangCache[LangCache.Length - 1].StrEntry = result;
  return result;
}
//---------------------------------------------------------------------------

UnicodeString __fastcall GetID(TStringList* LangFile, int Idx)
{
  if(Idx > LangFile->Count) return "???";
  UnicodeString result = LangFile->Strings[Idx - 1].Delete(1,LangFile->Strings[Idx-1].Pos("="));
  result = StringReplace(result, "#", "\x0d\x0a", TReplaceFlags() << rfReplaceAll);
  result = StringReplace(result, ";", "\x0d\x0a", TReplaceFlags() << rfReplaceAll);
  return result;
}
//---------------------------------------------------------------------------

void __fastcall LangForm(TForm* Form)
{
  UnicodeString FileName = LangPath + Form->ClassName() + ".lng";
  if(!FileExists(FileName)) return;
  TStringList* LangFile = new TStringList;
  LangFile->LoadFromFile(FileName);
  int Idx = Form->Tag;
  if(Idx > 0) Form->Caption = GetID(LangFile, Idx);
  for(int stop = Form->ComponentCount - 1, i = 0; i <= stop; i++)
  {
	if(dynamic_cast<TActionList*>(Form->Components[i]))
	{
	  for(int stop2 = ((TActionList*)Form->Components[i])->ActionCount - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TActionList*)Form->Components[i])->Actions[j]->Tag;
		if(Idx > 0)
		{
		  ((TActionList*)Form->Components[i])->Actions[j]->Caption = GetID(LangFile, Idx);
		  if(!((TActionList*)Form->Components[i])->Actions[j]->Hint.IsEmpty())
		   ((TActionList*)Form->Components[i])->Actions[j]->Hint = GetID(LangFile, Idx);
		}
	  }
	}
	if(dynamic_cast<TsButton*>(Form->Components[i]))
	{
	  Idx = ((TsButton*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(!((TsButton*)Form->Components[i])->Action))
	   ((TsButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsSpeedButton*>(Form->Components[i]))
	{
	  Idx = ((TsSpeedButton*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(!((TsSpeedButton*)Form->Components[i])->Action))
	   ((TsSpeedButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	  else if((Idx > 0)&&(((TsSpeedButton*)Form->Components[i])->ShowHint))
       ((TsSpeedButton*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TCategoryPanel*>(Form->Components[i]))
	{
	  Idx = ((TCategoryPanel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TCategoryPanel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsCheckBox*>(Form->Components[i]))
	{
	  Idx = ((TsCheckBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsCheckBox*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsColorSelect*>(Form->Components[i]))
	{
	  Idx = ((TsColorSelect*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsColorSelect*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsComboBox*>(Form->Components[i]))
	{
	  Idx = ((TsComboBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsComboBox*)Form->Components[i])->Items->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsComboBoxEx*>(Form->Components[i]))
	{
	  Idx = ((TsComboBoxEx*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsComboBoxEx*)Form->Components[i])->Items->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsEdit*>(Form->Components[i]))
	{
	  Idx = ((TsEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsMaskEdit*>(Form->Components[i]))
	{
	  Idx = ((TsMaskEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsMaskEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsMaskEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsMaskEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsSpinEdit*>(Form->Components[i]))
	{
	  Idx = ((TsSpinEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsSpinEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsSpinEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsSpinEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsGroupBox*>(Form->Components[i]))
	{
	  Idx = ((TsGroupBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsGroupBox*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsLabel*>(Form->Components[i]))
	{
	  Idx = ((TsLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsLabelFX*>(Form->Components[i]))
	{
	  Idx = ((TsLabelFX*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsLabelFX*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsHTMLLabel*>(Form->Components[i]))
	{
	  Idx = ((TsHTMLLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsHTMLLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsWebLabel*>(Form->Components[i]))
	{
	  Idx = ((TsWebLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsWebLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsStickyLabel*>(Form->Components[i]))
	{
	  Idx = ((TsStickyLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsStickyLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TLabeledEdit*>(Form->Components[i]))
	{
	  Idx = ((TLabeledEdit*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TLabeledEdit*)Form->Components[i])->EditLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsListBox*>(Form->Components[i]))
	{
	  Idx = ((TsListBox*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsListBox*)Form->Components[i])->BoundLabel->Active))
	   ((TsListBox*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsListView*>(Form->Components[i]))
	{
	  Idx = ((TsListView*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsListView*)Form->Components[i])->BoundLabel->Active))
	   ((TsListView*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	  for(int stop2 = ((TsListView*)Form->Components[i])->Columns->Count - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TsListView*)Form->Components[i])->Column[j]->Tag;
		if(Idx > 0) ((TsListView*)Form->Components[i])->Column[j]->Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TMainMenu*>(Form->Components[i]))
	{
	  for(int stop2 = ((TMainMenu*)Form->Components[i])->Items->Count - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TMainMenu*)Form->Components[i])->Items[j].Tag;
		if(Idx > 0) ((TMainMenu*)Form->Components[i])->Items[j].Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsMemo*>(Form->Components[i]))
	{
	  Idx = ((TsMemo*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsMemo*)Form->Components[i])->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsPageControl*>(Form->Components[i]))
	{
	  for(int stop2 = ((TsPageControl*)Form->Components[i])->PageCount - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TsPageControl*)Form->Components[i])->Pages[j]->Tag;
		if(Idx > 0) ((TsPageControl*)Form->Components[i])->Pages[j]->Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsRadioButton*>(Form->Components[i]))
	{
	  Idx = ((TsRadioButton*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsRadioButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsSlider*>(Form->Components[i]))
	{
	  Idx = ((TsSlider*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsSlider*)Form->Components[i])->BoundLabel->Active))
	   ((TsSlider*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsStatusBar*>(Form->Components[i]))
	{
	  Idx = ((TsStatusBar*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		((TsStatusBar*)Form->Components[i])->SimpleText = GetID(LangFile, Idx);
		if(!((TsStatusBar*)Form->Components[i])->SimplePanel)
		{
		  if(((TsStatusBar*)Form->Components[i])->Panels->Count > 0)
		   ((TsStatusBar*)Form->Components[i])->Panels->Items[0]->Text = GetID(LangFile, Idx);
        }
	  }
	}
	if(dynamic_cast<TsTrackBar*>(Form->Components[i]))
	{
	  Idx = ((TsTrackBar*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsTrackBar*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
  }
  delete LangFile;
}
//---------------------------------------------------------------------------

void __fastcall LangFrame(TFrame* Form)
{
  UnicodeString FileName = LangPath + Form->ClassName() + ".lng";
  if(!FileExists(FileName)) return;
  TStringList* LangFile = new TStringList;
  LangFile->LoadFromFile(FileName);
  int Idx;
  for(int stop = Form->ComponentCount - 1, i = 0; i <= stop; i++)
  {
    if(dynamic_cast<TActionList*>(Form->Components[i]))
	{
	  for(int stop2 = ((TActionList*)Form->Components[i])->ActionCount - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TActionList*)Form->Components[i])->Actions[j]->Tag;
		if(Idx > 0)
		{
		  ((TActionList*)Form->Components[i])->Actions[j]->Caption = GetID(LangFile, Idx);
		  if(!((TActionList*)Form->Components[i])->Actions[j]->Hint.IsEmpty())
		   ((TActionList*)Form->Components[i])->Actions[j]->Hint = GetID(LangFile, Idx);
		}
	  }
	}
	if(dynamic_cast<TsButton*>(Form->Components[i]))
	{
	  Idx = ((TsButton*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(!((TsButton*)Form->Components[i])->Action))
	   ((TsButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsSpeedButton*>(Form->Components[i]))
	{
	  Idx = ((TsSpeedButton*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(!((TsSpeedButton*)Form->Components[i])->Action))
	   ((TsSpeedButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	  else if((Idx > 0)&&(((TsSpeedButton*)Form->Components[i])->ShowHint))
       ((TsSpeedButton*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TCategoryPanel*>(Form->Components[i]))
	{
	  Idx = ((TCategoryPanel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TCategoryPanel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsCheckBox*>(Form->Components[i]))
	{
	  Idx = ((TsCheckBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsCheckBox*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsColorSelect*>(Form->Components[i]))
	{
	  Idx = ((TsColorSelect*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsColorSelect*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsComboBox*>(Form->Components[i]))
	{
	  Idx = ((TsComboBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsComboBox*)Form->Components[i])->Items->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsComboBoxEx*>(Form->Components[i]))
	{
	  Idx = ((TsComboBoxEx*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsComboBoxEx*)Form->Components[i])->Items->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsEdit*>(Form->Components[i]))
	{
	  Idx = ((TsEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsMaskEdit*>(Form->Components[i]))
	{
	  Idx = ((TsMaskEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsMaskEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsMaskEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsMaskEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsSpinEdit*>(Form->Components[i]))
	{
	  Idx = ((TsSpinEdit*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		if(((TsSpinEdit*)Form->Components[i])->BoundLabel->Active)
		 ((TsSpinEdit*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
		else
		 ((TsSpinEdit*)Form->Components[i])->TextHint = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsGroupBox*>(Form->Components[i]))
	{
	  Idx = ((TsGroupBox*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsGroupBox*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsLabel*>(Form->Components[i]))
	{
	  Idx = ((TsLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsLabelFX*>(Form->Components[i]))
	{
	  Idx = ((TsLabelFX*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsLabelFX*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsHTMLLabel*>(Form->Components[i]))
	{
	  Idx = ((TsHTMLLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsHTMLLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsWebLabel*>(Form->Components[i]))
	{
	  Idx = ((TsWebLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsWebLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsStickyLabel*>(Form->Components[i]))
	{
	  Idx = ((TsStickyLabel*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsStickyLabel*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TLabeledEdit*>(Form->Components[i]))
	{
	  Idx = ((TLabeledEdit*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TLabeledEdit*)Form->Components[i])->EditLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsListBox*>(Form->Components[i]))
	{
	  Idx = ((TsListBox*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsListBox*)Form->Components[i])->BoundLabel->Active))
	   ((TsListBox*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsListView*>(Form->Components[i]))
	{
	  Idx = ((TsListView*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsListView*)Form->Components[i])->BoundLabel->Active))
	   ((TsListView*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	  for(int stop2 = ((TsListView*)Form->Components[i])->Columns->Count - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TsListView*)Form->Components[i])->Column[j]->Tag;
		if(Idx > 0) ((TsListView*)Form->Components[i])->Column[j]->Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TMainMenu*>(Form->Components[i]))
	{
	  for(int stop2 = ((TMainMenu*)Form->Components[i])->Items->Count - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TMainMenu*)Form->Components[i])->Items[j].Tag;
		if(Idx > 0) ((TMainMenu*)Form->Components[i])->Items[j].Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsMemo*>(Form->Components[i]))
	{
	  Idx = ((TsMemo*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsMemo*)Form->Components[i])->Text = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsPageControl*>(Form->Components[i]))
	{
	  for(int stop2 = ((TsPageControl*)Form->Components[i])->PageCount - 1, j = 0; j <= stop2; j++)
	  {
		Idx = ((TsPageControl*)Form->Components[i])->Pages[j]->Tag;
		if(Idx > 0) ((TsPageControl*)Form->Components[i])->Pages[j]->Caption = GetID(LangFile, Idx);
	  }
	}
	if(dynamic_cast<TsRadioButton*>(Form->Components[i]))
	{
	  Idx = ((TsRadioButton*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsRadioButton*)Form->Components[i])->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsSlider*>(Form->Components[i]))
	{
	  Idx = ((TsSlider*)Form->Components[i])->Tag;
	  if((Idx > 0)&&(((TsSlider*)Form->Components[i])->BoundLabel->Active))
	   ((TsSlider*)Form->Components[i])->BoundLabel->Caption = GetID(LangFile, Idx);
	}
	if(dynamic_cast<TsStatusBar*>(Form->Components[i]))
	{
	  Idx = ((TsStatusBar*)Form->Components[i])->Tag;
	  if(Idx > 0)
	  {
		((TsStatusBar*)Form->Components[i])->SimpleText = GetID(LangFile, Idx);
		if(!((TsStatusBar*)Form->Components[i])->SimplePanel)
		{
		  if(((TsStatusBar*)Form->Components[i])->Panels->Count > 0)
		   ((TsStatusBar*)Form->Components[i])->Panels->Items[0]->Text = GetID(LangFile, Idx);
        }
	  }
	}
	if(dynamic_cast<TsTrackBar*>(Form->Components[i]))
	{
	  Idx = ((TsTrackBar*)Form->Components[i])->Tag;
	  if(Idx > 0) ((TsTrackBar*)Form->Components[i])->Hint = GetID(LangFile, Idx);
	}
  }
  delete LangFile;
}
//---------------------------------------------------------------------------
