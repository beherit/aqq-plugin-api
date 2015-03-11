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
	for(int Count=0; Count<LangCache.Length; Count++)
	{
		if(LangCache[Count].StrID == ID)
			return LangCache[Count].StrEntry;
	}
	UnicodeString FileName = LangPath + "Const.lng";
	if(!FileExists(FileName)) return "";
	UnicodeString result;
	TStringList* LangFile = new TStringList;
	try
	{
		LangFile->LoadFromFile(FileName, TEncoding::UTF8);
		for(int Count=0; Count<LangFile->Count; Count++)
		{
			if(LangFile->Strings[Count].Pos(ID + "=")==1)
			{
				result = LangFile->Strings[Count].Delete(1, ID.Length() + 1);
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
	UnicodeString result = LangFile->Strings[Idx - 1].Delete(1, LangFile->Strings[Idx - 1].Pos("="));
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
	LangFile->LoadFromFile(FileName, TEncoding::UTF8);
	int Idx = Form->Tag;
	if(Idx > 0) Form->Caption = GetID(LangFile, Idx);
	for(int Component=0; Component<Form->ComponentCount; Component++)
	{
		if(dynamic_cast<TActionList*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TActionList*)Form->Components[Component])->ActionCount; Count++)
			{
				Idx = ((TActionList*)Form->Components[Component])->Actions[Count]->Tag;
				if(Idx > 0)
				{
					((TActionList*)Form->Components[Component])->Actions[Count]->Caption = GetID(LangFile, Idx);
					if(!((TActionList*)Form->Components[Component])->Actions[Count]->Hint.IsEmpty())
						((TActionList*)Form->Components[Component])->Actions[Count]->Hint = GetID(LangFile, Idx);
				}
			}
		}
		if(dynamic_cast<TsButton*>(Form->Components[Component]))
		{
			Idx = ((TsButton*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(!((TsButton*)Form->Components[Component])->Action))
				((TsButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsSpeedButton*>(Form->Components[Component]))
		{
			Idx = ((TsSpeedButton*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsSpeedButton*)Form->Components[Component])->ShowHint)
					((TsSpeedButton*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
				else if(((TsSpeedButton*)Form->Components[Component])->Action)
					((TsSpeedButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TCategoryPanel*>(Form->Components[Component]))
		{
			Idx = ((TCategoryPanel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TCategoryPanel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsCheckBox*>(Form->Components[Component]))
		{
			Idx = ((TsCheckBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsCheckBox*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsColorSelect*>(Form->Components[Component]))
		{
			Idx = ((TsColorSelect*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsColorSelect*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsComboBox*>(Form->Components[Component]))
		{
			Idx = ((TsComboBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsComboBox*)Form->Components[Component])->Items->Text = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsComboBoxEx*>(Form->Components[Component]))
		{
			Idx = ((TsComboBoxEx*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsComboBoxEx*)Form->Components[Component])->Items->Text = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsEdit*>(Form->Components[Component]))
		{
			Idx = ((TsEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsMaskEdit*>(Form->Components[Component]))
		{
			Idx = ((TsMaskEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsMaskEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsMaskEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsMaskEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsSpinEdit*>(Form->Components[Component]))
		{
			Idx = ((TsSpinEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsSpinEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsSpinEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsSpinEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsGroupBox*>(Form->Components[Component]))
		{
			Idx = ((TsGroupBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsGroupBox*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsLabel*>(Form->Components[Component]))
		{
			Idx = ((TsLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsLabelFX*>(Form->Components[Component]))
		{
			Idx = ((TsLabelFX*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsLabelFX*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsHTMLLabel*>(Form->Components[Component]))
		{
			Idx = ((TsHTMLLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsHTMLLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsWebLabel*>(Form->Components[Component]))
		{
			Idx = ((TsWebLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsWebLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsStickyLabel*>(Form->Components[Component]))
		{
			Idx = ((TsStickyLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsStickyLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TLabeledEdit*>(Form->Components[Component]))
		{
			Idx = ((TLabeledEdit*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TLabeledEdit*)Form->Components[Component])->EditLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsListBox*>(Form->Components[Component]))
		{
			Idx = ((TsListBox*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsListBox*)Form->Components[Component])->BoundLabel->Active))
				((TsListBox*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsListView*>(Form->Components[Component]))
		{
			Idx = ((TsListView*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsListView*)Form->Components[Component])->BoundLabel->Active))
				((TsListView*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
			for(int Count=0; Count<((TsListView*)Form->Components[Component])->Columns->Count; Count++)
			{
				Idx = ((TsListView*)Form->Components[Component])->Column[Count]->Tag;
				if(Idx > 0) ((TsListView*)Form->Components[Component])->Column[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TMainMenu*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TMainMenu*)Form->Components[Component])->Items->Count; Count++)
			{
				Idx = ((TMainMenu*)Form->Components[Component])->Items[Count].Tag;
				if(Idx > 0) ((TMainMenu*)Form->Components[Component])->Items[Count].Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsMemo*>(Form->Components[Component]))
		{
			Idx = ((TsMemo*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsMemo*)Form->Components[Component])->ShowHint)
					((TsMemo*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
				else
					((TsMemo*)Form->Components[Component])->Text = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsPageControl*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TsPageControl*)Form->Components[Component])->PageCount; Count++)
			{
				Idx = ((TsPageControl*)Form->Components[Component])->Pages[Count]->Tag;
				if(Idx > 0) ((TsPageControl*)Form->Components[Component])->Pages[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TPopupMenu*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TPopupMenu*)Form->Components[Component])->Items->Count; Count++)
			{
				Idx = ((TPopupMenu*)Form->Components[Component])->Items->Items[Count]->Tag;
				if(Idx > 0) ((TPopupMenu*)Form->Components[Component])->Items->Items[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsRadioButton*>(Form->Components[Component]))
		{
			Idx = ((TsRadioButton*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsRadioButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsSlider*>(Form->Components[Component]))
		{
			Idx = ((TsSlider*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsSlider*)Form->Components[Component])->BoundLabel->Active))
				((TsSlider*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsStatusBar*>(Form->Components[Component]))
		{
			Idx = ((TsStatusBar*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				((TsStatusBar*)Form->Components[Component])->SimpleText = GetID(LangFile, Idx);
				if(!((TsStatusBar*)Form->Components[Component])->SimplePanel)
				{
					if(((TsStatusBar*)Form->Components[Component])->Panels->Count > 0)
						((TsStatusBar*)Form->Components[Component])->Panels->Items[0]->Text = GetID(LangFile, Idx);
				}
			}
		}
		if(dynamic_cast<TsTrackBar*>(Form->Components[Component]))
		{
			Idx = ((TsTrackBar*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsTrackBar*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
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
	LangFile->LoadFromFile(FileName, TEncoding::UTF8);
	int Idx;
	for(int Component=0; Component<Form->ComponentCount; Component++)
	{
		if(dynamic_cast<TActionList*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TActionList*)Form->Components[Component])->ActionCount; Count++)
			{
				Idx = ((TActionList*)Form->Components[Component])->Actions[Count]->Tag;
				if(Idx > 0)
				{
					((TActionList*)Form->Components[Component])->Actions[Count]->Caption = GetID(LangFile, Idx);
					if(!((TActionList*)Form->Components[Component])->Actions[Count]->Hint.IsEmpty())
						((TActionList*)Form->Components[Component])->Actions[Count]->Hint = GetID(LangFile, Idx);
				}
			}
		}
		if(dynamic_cast<TsButton*>(Form->Components[Component]))
		{
			Idx = ((TsButton*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(!((TsButton*)Form->Components[Component])->Action))
				((TsButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsSpeedButton*>(Form->Components[Component]))
		{
			Idx = ((TsSpeedButton*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsSpeedButton*)Form->Components[Component])->ShowHint)
					((TsSpeedButton*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
				else if(((TsSpeedButton*)Form->Components[Component])->Action)
					((TsSpeedButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TCategoryPanel*>(Form->Components[Component]))
		{
			Idx = ((TCategoryPanel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TCategoryPanel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsCheckBox*>(Form->Components[Component]))
		{
			Idx = ((TsCheckBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsCheckBox*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsColorSelect*>(Form->Components[Component]))
		{
			Idx = ((TsColorSelect*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsColorSelect*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsComboBox*>(Form->Components[Component]))
		{
			Idx = ((TsComboBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsComboBox*)Form->Components[Component])->Items->Text = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsComboBoxEx*>(Form->Components[Component]))
		{
			Idx = ((TsComboBoxEx*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsComboBoxEx*)Form->Components[Component])->Items->Text = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsEdit*>(Form->Components[Component]))
		{
			Idx = ((TsEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsMaskEdit*>(Form->Components[Component]))
		{
			Idx = ((TsMaskEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsMaskEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsMaskEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsMaskEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsSpinEdit*>(Form->Components[Component]))
		{
			Idx = ((TsSpinEdit*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsSpinEdit*)Form->Components[Component])->BoundLabel->Active)
					((TsSpinEdit*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
				else
					((TsSpinEdit*)Form->Components[Component])->TextHint = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsGroupBox*>(Form->Components[Component]))
		{
			Idx = ((TsGroupBox*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsGroupBox*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsLabel*>(Form->Components[Component]))
		{
			Idx = ((TsLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsLabelFX*>(Form->Components[Component]))
		{
			Idx = ((TsLabelFX*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsLabelFX*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsHTMLLabel*>(Form->Components[Component]))
		{
			Idx = ((TsHTMLLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsHTMLLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsWebLabel*>(Form->Components[Component]))
		{
			Idx = ((TsWebLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsWebLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsStickyLabel*>(Form->Components[Component]))
		{
			Idx = ((TsStickyLabel*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsStickyLabel*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TLabeledEdit*>(Form->Components[Component]))
		{
			Idx = ((TLabeledEdit*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TLabeledEdit*)Form->Components[Component])->EditLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsListBox*>(Form->Components[Component]))
		{
			Idx = ((TsListBox*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsListBox*)Form->Components[Component])->BoundLabel->Active))
				((TsListBox*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsListView*>(Form->Components[Component]))
		{
			Idx = ((TsListView*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsListView*)Form->Components[Component])->BoundLabel->Active))
				((TsListView*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
			for(int Count=0; Count<((TsListView*)Form->Components[Component])->Columns->Count; Count++)
			{
				Idx = ((TsListView*)Form->Components[Component])->Column[Count]->Tag;
				if(Idx > 0) ((TsListView*)Form->Components[Component])->Column[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TMainMenu*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TMainMenu*)Form->Components[Component])->Items->Count; Count++)
			{
				Idx = ((TMainMenu*)Form->Components[Component])->Items[Count].Tag;
				if(Idx > 0) ((TMainMenu*)Form->Components[Component])->Items[Count].Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsMemo*>(Form->Components[Component]))
		{
			Idx = ((TsMemo*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				if(((TsMemo*)Form->Components[Component])->ShowHint)
					((TsMemo*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
				else
					((TsMemo*)Form->Components[Component])->Text = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsPageControl*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TsPageControl*)Form->Components[Component])->PageCount; Count++)
			{
				Idx = ((TsPageControl*)Form->Components[Component])->Pages[Count]->Tag;
				if(Idx > 0) ((TsPageControl*)Form->Components[Component])->Pages[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TPopupMenu*>(Form->Components[Component]))
		{
			for(int Count=0; Count<((TPopupMenu*)Form->Components[Component])->Items->Count; Count++)
			{
				Idx = ((TPopupMenu*)Form->Components[Component])->Items->Items[Count]->Tag;
				if(Idx > 0) ((TPopupMenu*)Form->Components[Component])->Items->Items[Count]->Caption = GetID(LangFile, Idx);
			}
		}
		if(dynamic_cast<TsRadioButton*>(Form->Components[Component]))
		{
			Idx = ((TsRadioButton*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsRadioButton*)Form->Components[Component])->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsSlider*>(Form->Components[Component]))
		{
			Idx = ((TsSlider*)Form->Components[Component])->Tag;
			if((Idx > 0)&&(((TsSlider*)Form->Components[Component])->BoundLabel->Active))
				((TsSlider*)Form->Components[Component])->BoundLabel->Caption = GetID(LangFile, Idx);
		}
		if(dynamic_cast<TsStatusBar*>(Form->Components[Component]))
		{
			Idx = ((TsStatusBar*)Form->Components[Component])->Tag;
			if(Idx > 0)
			{
				((TsStatusBar*)Form->Components[Component])->SimpleText = GetID(LangFile, Idx);
				if(!((TsStatusBar*)Form->Components[Component])->SimplePanel)
				{
					if(((TsStatusBar*)Form->Components[Component])->Panels->Count > 0)
						((TsStatusBar*)Form->Components[Component])->Panels->Items[0]->Text = GetID(LangFile, Idx);
				}
			}
		}
		if(dynamic_cast<TsTrackBar*>(Form->Components[Component]))
		{
			Idx = ((TsTrackBar*)Form->Components[Component])->Tag;
			if(Idx > 0) ((TsTrackBar*)Form->Components[Component])->Hint = GetID(LangFile, Idx);
		}
	}
	delete LangFile;
}
//---------------------------------------------------------------------------
