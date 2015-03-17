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
#ifndef LANGAPI_H
#define LANGAPI_H
#pragma hdrstop
#pragma comment(lib, "LangAPI")
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