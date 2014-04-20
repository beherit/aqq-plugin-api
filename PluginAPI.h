//---------------------------------------------------------------------------
//Przetłumaczone SDK komunikatora AQQ z języka Delphi na bardziej ludzki C++
//---------------------------------------------------------------------------
//Środowisko: Embarcadero C++ Builder
//Pełen opis: http://adn.beherit.pl
//Autor: Krzysztof Grochocki
//WWW: http://beherit.pl
//E-mail: kontakt@beherit.pl
//Jabber: im@beherit.pl
//---------------------------------------------------------------------------

#ifndef AQQ_H
#define AQQ_H

//HOOKS----------------------------------------------------------------------

//System
#define AQQ_SYSTEM_BEFOREUNLOAD L"AQQ/System/BeforeUnload"
#define AQQ_SYSTEM_PRECONFIG L"AQQ/System/PreConfig"
#define AQQ_SYSTEM_NOTIFICATIONCLOSED L"AQQ/System/NotificationClosed"
#define AQQ_SYSTEM_NEWSSOURCE_ADD L"AQQ/System/NewsSource/Add"
#define AQQ_SYSTEM_NEWSSOURCE_DELETE L"AQQ/System/NewsSource/Delete"
#define AQQ_SYSTEM_NEWSSOURCE_UPDATE L"AQQ/System/NewsSource/Update"
#define AQQ_SYSTEM_NEWSSOURCE_ACTIVE L"AQQ/System/NewsSource/Active"
#define AQQ_SYSTEM_NEWSSOURCE_REFRESH L"AQQ/System/NewsSource/Refresh"
#define AQQ_SYSTEM_NEWSSOURCE_BEFOREFETCH L"AQQ/System/NewsSource/BeforeFetch"
#define AQQ_SYSTEM_NEWSSOURCE_FETCH L"AQQ/System/NewsSource/Fetch"
#define AQQ_SYSTEM_NEWSSOURCE_FETCHSTART L"AQQ/System/NewsSource/FetchStart"
#define AQQ_SYSTEM_NEWSSOURCE_FETCHEND L"AQQ/System/NewsSource/FetchEnd"
#define AQQ_SYSTEM_NEWSSOURCE_ITEM L"AQQ/System/NewsSource/Item"
#define AQQ_SYSTEM_GETACCOUNTINFO L"AQQ/System/GetAccountInfo"
#define AQQ_SYSTEM_POPUP L"AQQ/System/Popup"
#define AQQ_SYSTEM_MULTIPOPUP L"AQQ/System/MultiPopup"
#define AQQ_SYSTEM_CHAT_PRESENCE L"AQQ/System/Chat/Presence"
#define AQQ_SYSTEM_CHAT_OPEN L"AQQ/System/Chat/Open"
#define AQQ_SYSTEM_CURRENTSONG L"AQQ/System/CurrentSong"
#define AQQ_SYSTEM_MSGCOMPOSING L"AQQ/System/MsgComposing"
#define AQQ_SYSTEM_ERROR L"AQQ/System/Error"
#define AQQ_SYSTEM_SENDHOOK L"AQQ/System/SendHook"
#define AQQ_SYSTEM_MODULESLOADED L"AQQ/System/ModulesLoaded"
#define AQQ_SYSTEM_ADDSMSGATE L"AQQ/System/AddSMSGate"
#define AQQ_SYSTEM_REMOVESMSGATE L"AQQ/System/RemoveSMSGate"
#define AQQ_SYSTEM_RENAMESMSGATE L"AQQ/System/RenameSMSGate"
#define AQQ_SYSTEM_GETAGENTS L"AQQ/System/GetAgents"
#define AQQ_SYSTEM_SETAGENT L"AQQ/System/SetAgent"
#define AQQ_SYSTEM_ISAGENTENABLED L"AQQ/System/IsAgentEnabled"
#define AQQ_SYSTEM_REMOVEAGENT L"AQQ/System/RemoveAgent"
#define AQQ_SYSTEM_GETIMPEXP L"AQQ/System/GetImpExp"
#define AQQ_SYSTEM_ADDIMPEXP L"AQQ/System/AddImpExp"
#define AQQ_SYSTEM_QUERY L"AQQ/System/Query"
#define AQQ_SYSTEM_QUERYEX L"AQQ/System/QueryEx"
#define AQQ_SYSTEM_SMSSUPPORTED L"AQQ/System/SMSSupported"
#define AQQ_SYSTEM_SMSCONFIG L"AQQ/System/SMSConfig"
#define AQQ_SYSTEM_SMSSEND L"AQQ/System/SMSSend"
#define AQQ_SYSTEM_SETNOTE L"AQQ/System/SetNote"
#define AQQ_SYSTEM_WINDOWEVENT L"AQQ/System/WindowEvent"
#define AQQ_SYSTEM_STATECHANGE L"AQQ/System/StateChange"
#define AQQ_SYSTEM_SETLASTSTATE L"AQQ/System/SetLastState"
#define AQQ_SYSTEM_CHANGE_JABBERRESOURCES L"AQQ/System/Change/Resources"
#define AQQ_SYSTEM_RUNACTION L"AQQ/System/RunAction"
#define AQQ_SYSTEM_SENDXML L"AQQ/System/SendXML"
#define AQQ_SYSTEM_XMLIDDEBUG L"AQQ/System/XMLIDDebug"
#define AQQ_SYSTEM_XMLDEBUG L"AQQ/System/XMLDebug"
#define AQQ_SYSTEM_ONLINECHECK L"AQQ/System/OnlineCheck"
#define AQQ_SYSTEM_DEBUG_XML L"AQQ/System/Debug/XML"
#define AQQ_SYSTEM_DISCONNECT L"AQQ/System/Disconnect"
#define AQQ_SYSTEM_AUTOMATION_AUTOAWAY_ON L"AQQ/System/Automation/AutoAway/On"
#define AQQ_SYSTEM_AUTOMATION_AUTOAWAY_OFF L"AQQ/System/Automation/AutoAway/Off"
#define AQQ_SYSTEM_ONCONNECT_SILENCE L"AQQ/System/OnConnect/Silence"
#define AQQ_SYSTEM_GETCURRENTSHOWTYPE_PATH L"AQQ/System/GetCurrentShowType/Path"
#define AQQ_SYSTEM_GETCURRENTUID L"AQQ/System/GetCurrentUID"
#define AQQ_SYSTEM_THEMECHANGED L"AQQ/System/ThemeChanged"
#define AQQ_SYSTEM_THEMEINFO L"AQQ/System/ThemeInfo"
#define AQQ_SYSTEM_THEMESTART L"AQQ/System/ThemeStart"
#define AQQ_SYSTEM_MAXSTATUSLENGTH L"AQQ/System/MaxStatusLength"
#define AQQ_SYSTEM_MAXMSGLENGTH L"AQQ/System/MaxMsgLength"
#define AQQ_SYSTEM_GETNEWCACHEITEMPATH L"AQQ/System/GetNewCacheItemPath"
#define AQQ_SYSTEM_PERFORM_COPYDATA L"AQQ/System/Perform/CopyData"
#define AQQ_SYSTEM_FORCESTATUS L"AQQ/System/ForceStatus"
#define AQQ_SYSTEM_CLIPBOARD_JID L"AQQ/System/Clipboard/JID"
#define AQQ_SYSTEM_TABCHANGE L"AQQ/System/TabChange"
#define AQQ_SYSTEM_INTERPRET_XML L"AQQ/System/Interpret/XML"
#define AQQ_SYSTEM_TRANSFER_STATUS_CHANGE L"AQQ/System/Transfer/Status/Change"
#define AQQ_SYSTEM_AUTOMATION_AUTOSECURE L"AQQ/System/Automation/AutoSecure"
#define AQQ_SYSTEM_AUTOSECURE_ON L"AQQ/System/AutoSecure/On"
#define AQQ_SYSTEM_AUTOSECURE_OFF L"AQQ/System/AutoSecure/Off"
#define AQQ_SYSTEM_MSGCONTEXT_POPUP L"AQQ/System/OnMsgContent/Popup"
#define AQQ_SYSTEM_MSGCONTEXT_CLOSE L"AQQ/System/OnMsgContent/Close"
#define AQQ_SYSTEM_CHANGESMS_STATUS L"AQQ/System/ChangeSMS/Status"
#define AQQ_SYSTEM_CHANGESMS_ID L"AQQ/System/ChangeSMS/ID"
#define AQQ_SYSTEM_TOOLTIP_FILL L"AQQ/System/ToolTip/Fill"
#define AQQ_SYSTEM_ADDONINSTALLED L"AQQ/System/AddonInstalled"
#define AQQ_SYSTEM_TOOLTIP_BEFORESHOW L"AQQ/System/ToolTip/BeforeShow"
#define AQQ_SYSTEM_TOOLTIP_ADDITEM L"AQQ/System/ToolTip/AddItem"
#define AQQ_SYSTEM_TOOLTIP_SHOW L"AQQ/System/ToolTip/Show"
#define AQQ_SYSTEM_CONNECTION_STATE L"AQQ/System/Connection/State"
#define AQQ_SYSTEM_THEME_SET L"AQQ/System/Theme/Set"
#define AQQ_SYSTEM_THEME_APPLY L"AQQ/System/Theme/Apply"
#define AQQ_SYSTEM_THEME_REFRESH L"AQQ/System/Theme/Refresh"
#define AQQ_SYSTEM_CHAT L"AQQ/System/Chat"
#define AQQ_SYSTEM_SETSHOWANDSTATUS L"AQQ/System/SetShowAndStatus"
#define AQQ_SYSTEM_SETUPDATELINK L"AQQ/System/SetUpdateLink"
#define AQQ_SYSTEM_FUNCTION_SETENABLED L"AQQ/System/SetEnabled"
#define AQQ_SYSTEM_ACCOUNT_EVENTS L"AQQ/System/Account/Events"
#define AQQ_SYSTEM_ACCOUNT_RUNEVENT L"AQQ/System/Account/RunEvent"
#define AQQ_SYSTEM_RESTART L"AQQ/System/Restart"
#define AQQ_SYSTEM_PLUGIN_REFRESHLIST L"AQQ/System/Plugin/RefreshList"
#define AQQ_SYSTEM_PLUGIN_EXCLUDE L"AQQ/System/Plugin/Exclude"
#define AQQ_SYSTEM_PLUGIN_ACTIVE L"AQQ/System/Plugin/Active"
#define AQQ_SYSTEM_PLAYSOUND L"AQQ/System/Plugin/PlaySound"
#define AQQ_SYSTEM_ADDONBROWSER_URL L"AQQ/System/AddonBrowser/URL"
#define AQQ_SYSTEM_SKYPE_CONVSERSATION L"AQQ/System/Skype/Conversation"
#define AQQ_SYSTEM_TRAY_CLICK L"AQQ/System/Tray/Click"
#define AQQ_SYSTEM_LASTURL L"AQQ/System/LastURL"
#define AQQ_SYSTEM_REGEXP L"AQQ/System/RegExp"
#define AQQ_SYSTEM_FRAMESETTINGS L"AQQ/System/FrameSettings"
#define AQQ_SYSTEM_COLORCHANGE L"AQQ/System/ColorChange"
#define AQQ_SYSTEM_COLORGETHUE L"AQQ/System/ColorGetHue"
#define AQQ_SYSTEM_COLORGETSATURATION L"AQQ/System/ColorGetSaturation"
#define AQQ_SYSTEM_APPVER L"AQQ/System/AppVer"

//Windows
#define AQQ_WINDOW_SETNOTE_PUTNOTE L"AQQ/Window/SetNote/PutNote"
#define AQQ_WINDOW_SETNOTE_NOTEJID L"AQQ/Window/SetNote/NoteJID"
#define AQQ_WINDOW_SETSTATUS L"AQQ/Window/SetStatus"
#define AQQ_WINDOW_PRESETNOTE_NOTE L"AQQ/Window/PreSetNote/Note"
#define AQQ_WINDOW_SETNOTE_CLOSE L"AQQ/Window/SetNote/Close"
#define AQQ_WINDOW_TRANSPARENT L"AQQ/Window/Transparent"

//Toolbars
#define AQQ_CONTROLS_TOOLBAR L"AQQ/Controls/Toolbar/"
#define AQQ_CONTROLS_CREATEBUTTON L"/CreateButton"
#define AQQ_CONTROLS_DESTROYBUTTON L"/DestroyButton"
#define AQQ_CONTROLS_UPDATEBUTTON L"/UpdateButton"

//IE controls
#define AQQ_CONTROLS_WEBBROWSER_CREATE L"AQQ/Controls/WebBrowser/Create"
#define AQQ_CONTROLS_WEBBROWSER_NAVIGATE L"AQQ/Controls/WebBrowser/Navigate"
#define AQQ_CONTROLS_WEBBROWSER_NAVCOMPLETE L"AQQ/Controls/WebBrowser/NavComplete"
#define AQQ_CONTROLS_WEBBROWSER_SETID L"AQQ/Controls/WebBrowser/SetID"
#define AQQ_CONTROLS_WEBBROWSER_GETID L"AQQ/Controls/WebBrowser/GetID"
#define AQQ_CONTROLS_WEBBROWSER_BEFORENAV L"AQQ/Controls/WebBrowser/BeforeNav"
#define AQQ_CONTROLS_WEBBROWSER_STATUSCHANGE L"AQQ/Controls/WebBrowser/StatusChange"
#define AQQ_CONTROLS_WEBBROWSER_TITLECHANGE L"AQQ/Controls/WebBrowser/TitleChange"
#define AQQ_CONTROLS_WEBBROWSER_DESTROY L"AQQ/Controls/WebBrowser/Destroy"
#define AQQ_CONTROLS_WEBBROWSER_CLICKID L"AQQ/Controls/WebBrowser/ClickID"

//Menus
#define AQQ_CONTROLS_GETPOPUPMENUITEM L"AQQ/Controls/GetPopupMenuItem"
#define AQQ_CONTROLS_EDITPOPUPMENUITEM L"AQQ/Controls/EditPopUpMenuItem"
#define AQQ_CONTROLS_CREATEPOPUPMENU L"AQQ/Controls/CreatePopUpMenu"
#define AQQ_CONTROLS_CREATEPOPUPMENUITEM L"AQQ/Controls/CreatePopUpMenuItem"
#define AQQ_CONTROLS_DESTROYPOPUPMENU L"AQQ/Controls/DestroyPopUpMenu"
#define AQQ_CONTROLS_DESTROYPOPUPMENUITEM L"AQQ/Controls/DestroyPopUpMenuItem"

//Other controls
#define AQQ_CONTROLS_MAINSTATUS_SETPANELTEXT L"AQQ/Controls/MainStatus/SetPanelText"
#define AQQ_CONTROLS_SMSCONTROLS_ENABLE L"AQQ/Controls/SMSControls/Enable"
#define AQQ_CONTROLS_FORM_CREATE L"AQQ/Controls/Form/Create"
#define AQQ_CONTROLS_FORM_DESTROY L"AQQ/Controls/Form/Destroy"
#define AQQ_CONTROLS_FORM_VISIBLE L"AQQ/Controls/Form/Destroy"
#define AQQ_CONTROLS_FORM_CONTROL L"AQQ/Controls/Form/Control"
#define AQQ_CONTROLS_FORM_GETMODALRESULT L"AQQ/Controls/Form/GetModalResult"

//Contacts
#define AQQ_CONTACTS_LISTREADY L"AQQ/Contacts/ListReady"
#define AQQ_CONTACTS_FROMPLUGIN L"AQQ/Contacts/FromPlugin"
#define AQQ_CONTACTS_FILLSIMPLEINFO L"AQQ/Contacts/FillSimpleInfo"
#define AQQ_CONTACTS_SET_SIMPLEINFO L"AQQ/Contacts/Set/SimpleInfo"
#define AQQ_CONTACTS_REQUESTBUDDY L"AQQ/Contacts/RequestBuddy"
#define AQQ_CONTACTS_GET_SIMPLEINFO L"AQQ/Contacts/Get/SimpleInfo"
#define AQQ_CONTACTS_ADD_BAN L"AQQ/Contacts/Add/Ban"
#define AQQ_CONTACTS_REMOVE_BAN L"AQQ/Contacts/Remove/Ban"
#define AQQ_CONTACTS_HAVE_BAN L"AQQ/Contacts/Have/Ban"
#define AQQ_CONTACTS_ADD L"AQQ/Contacts/Add"
#define AQQ_CONTACTS_CREATE L"AQQ/Contacts/Create"
#define AQQ_CONTACTS_ADDFORM L"AQQ/Contacts/AddForm"
#define AQQ_CONTACTS_UPDATEGROUPS L"AQQ/Contacts/UpdateGroups"
#define AQQ_CONTACTS_DELETE L"AQQ/Contacts/Delete"
#define AQQ_CONTACTS_DESTROYDOMAIN L"AQQ/Contacts/DestroyDomain"
#define AQQ_CONTACTS_UPDATE L"AQQ/Contacts/Update"
#define AQQ_CONTACTS_BUDDYFILL L"AQQ/Contacts/BuddyFill"
#define AQQ_CONTACTS_MESSAGE L"AQQ/Contacts/Message"
#define AQQ_CONTACTS_PRESENDMSG L"AQQ/Contacts/PreSendMsg"
#define AQQ_CONTACTS_SENDMSG L"AQQ/Contacts/SendMsg"
#define AQQ_CONTACTS_RECVMSG L"AQQ/Contacts/RecvMsg"
#define AQQ_CONTACTS_ACKMSG L"AQQ/Contacts/AckMsg"
#define AQQ_CONTACTS_ADDLINE L"AQQ/Contacts/AddLine"
#define AQQ_CONTACTS_ADDLINEINFO L"AQQ/Contacts/AddLineInfo"
#define AQQ_CONTACTS_REQUESTLIST L"AQQ/Contacts/RequestList"
#define AQQ_CONTACTS_REPLYLIST L"AQQ/Contacts/ReplyList"
#define AQQ_CONTACTS_REPLYLISTEND L"AQQ/Contacts/ReplyListEnd"
#define AQQ_CONTACTS_SETHTMLSTATUS L"AQQ/Contacts/SetHTMLStatus"
#define AQQ_CONTACTS_GETHTMLSTATUS L"AQQ/Contacts/GetHTMLStatus"
#define AQQ_CONTACTS_SENDPIC L"AQQ/Contacts/SendPic"
#define AQQ_CONTACTS_SENDPIC_SIZECHECK L"AQQ/Contacts/SendPic/SizeCheck"
#define AQQ_CONTACTS_SENDFILE L"AQQ/Contacts/SendFile"
#define AQQ_CONTACTS_ICONSHOWTYPE_PATH L"AQQ/Contacts/IconShowType/Path"
#define AQQ_CONTACTS_ICONSHOWTYPE_INDEX L"AQQ/Contacts/IconShowType/Index"
#define AQQ_CONTACTS_ICONSHOWTYPEJID_INDEX L"AQQ/Contacts/IconShowTypeJID/Index"
#define AQQ_CONTACTS_ICONSHOWTYPE_HDINDEX L"AQQ/Contacts/IconShowType/HDIndex"
#define AQQ_CONTACTS_SETOFFLINE L"AQQ/Contacts/SetOffline"
#define AQQ_CONTACTS_OFFLINE L"AQQ/Contacts/Offline"
#define AQQ_CONTACTS_GETSEARCHXML L"AQQ/Contacts/GetSearchXML"
#define AQQ_CONTACTS_SETSEARCHXML L"AQQ/Contacts/SetSearchXML"
#define AQQ_CONTACTS_RESSEARCHXML L"AQQ/Contacts/ResSearchXML"
#define AQQ_CONTACTS_ERRSEARCHXML L"AQQ/Contacts/ErrSearchXML"
#define AQQ_CONTACTS_LASTSEARCHID L"AQQ/Contacts/LastSearchID"
#define AQQ_CONTACTS_CHANGENAME L"AQQ/Contacts/ChangeName"
#define AQQ_CONTACTS_CHANGEGROUPNAME L"AQQ/Contacts/ChangeGroupName"
#define AQQ_CONTACTS_GETVCARD L"AQQ/Contacts/GetVCard"
#define AQQ_CONTACTS_RESVCARD L"AQQ/Contacts/ResVCard"
#define AQQ_CONTACTS_BUDDY_SELECTED L"AQQ/Contacts/Buddy/Selected"
#define AQQ_CONTACTS_BUDDY_ACTIVETAB L"AQQ/Contacts/Buddy/ActiveTab"
#define AQQ_CONTACTS_BUDDY_CLOSETAB L"AQQ/Contacts/Buddy/CloseTab"
#define AQQ_CONTACTS_BUDDY_CLOSETABMESSAGE L"AQQ/Contacts/Buddy/CloseTabMessage"
#define AQQ_CONTACTS_BUDDY_FORMACTIVATE L"AQQ/Contacts/Buddy/FormActive"
#define AQQ_CONTACTS_BUDDY_FETCHALLTABS L"AQQ/Contacts/Buddy/FetchAllTabs"
#define AQQ_CONTACTS_BUDDY_PRIMARYTAB L"AQQ/Contacts/Buddy/PrimaryTab"
#define AQQ_CONTACTS_BUDDY_CONFERENCETAB L"AQQ/Contacts/Buddy/ConferenceTab"
#define AQQ_CONTACTS_BUDDY_TABCAPTION L"AQQ/Contacts/Buddy/TabCaption"
#define AQQ_CONTACTS_BUDDY_TABIMAGE L"AQQ/Contacts/Buddy/TabImage"
#define AQQ_CONTACTS_SETWEB_AVATAR L"AQQ/Contacts/SetWeb/Avatar"
#define AQQ_CONTACTS_SET_AVATAR L"AQQ/Contacts/Set/Avatar"
#define AQQ_CONTACTS_STATUSCAPTION L"AQQ/Contacts/StatusCaption"
#define AQQ_CONTACTS_RESETAVATAR L"AQQ/Contacts/ResetAvatar"
#define AQQ_CONTACTS_ATTENTION L"AQQ/Contacts/Attention"
#define AQQ_CONTACTS_VALIDATEJID L"AQQ/Contacts/ValidateJID"
#define AQQ_CONTACTS_BUDDY_FETCHSELECTED L"AQQ/Contacts/Buddy/FetchSelected"
#define AQQ_CONTACTS_SETINVISIBLE L"AQQ/Contacts/SetInvisible"
#define AQQ_CONTACTS_GETINVISIBLE L"AQQ/Contacts/GetInvisible"
  
//Icons
#define AQQ_ICONS_LOADPNGICON L"AQQ/Icons/LoadPNGIcon"
#define AQQ_ICONS_REPLACEPNGICON L"AQQ/Icons/ReplacePNGIcon"
#define AQQ_ICONS_DESTROYPNGICON L"AQQ/Icons/DestroyPNGIcon"

//Functions
#define AQQ_FUNCTION_ISLISTREADY L"AQQ/Function/IsListReady"
#define AQQ_FUNCTION_GETPLUGINDIR L"AQQ/Function/GetPluginDir"
#define AQQ_FUNCTION_GETUSERDIR L"AQQ/Function/GetUserDir"
#define AQQ_FUNCTION_GETPLUGINUSERDIR L"AQQ/Function/GetPluginUserDir"
#define AQQ_FUNCTION_GETLANGSTR L"AQQ/Function/GetLangStr"
#define AQQ_FUNCTION_GETTOKEN L"AQQ/Function/GetToken"
#define AQQ_FUNCTION_GETSTRID L"AQQ/Function/GetStrID"
#define AQQ_FUNCTION_GETNUMID L"AQQ/Function/GetNumID"
#define AQQ_FUNCTION_GETUSERUID L"AQQ/Function/GetUserUID"
#define AQQ_FUNCTION_GETTHEMEDIRRW L"AQQ/Function/GetThemeDirRW"
#define AQQ_FUNCTION_GETTHEMEDIR L"AQQ/Function/GetThemeDir"
#define AQQ_FUNCTION_GETPROXY L"AQQ/Function/GetProxy"
#define AQQ_FUNCTION_GETAPPPATH L"AQQ/Function/GetAppPath"
#define AQQ_FUNCTION_GETAPPFILEPATH L"AQQ/Function/GetAppFilePath"
#define AQQ_FUNCTION_EXECUTEMSG L"AQQ/Function/ExecuteMsg"
#define AQQ_FUNCTION_EXECUTEMSG_NOPRIORITY L"AQQ/Function/ExecuteMsg/NoPriority"
#define AQQ_FUNCTION_MSGWINDOW L"AQQ/Function/Msgwindow"
#define AQQ_FUNCTION_TABWASCLOSED L"AQQ/Function/TabWasClosed"
#define AQQ_FUNCTION_TABMOVE L"AQQ/Function/TabMove"
#define AQQ_FUNCTION_TABCOUNT L"AQQ/Function/TabCount"
#define AQQ_FUNCTION_TABINDEX L"AQQ/Function/TabIndex"
#define AQQ_FUNCTION_OPENURL L"AQQ/Function/OpenURL"
#define AQQ_FUNCTION_OPENYTURL L"AQQ/Function/OpenYTURL"
#define AQQ_FUNCTION_GETEXTERNALIP L"AQQ/Function/GetExternalIP"
#define AQQ_FUNCTION_GETUSEREXCOUNT L"AQQ/Function/GetUserExCount"
#define AQQ_FUNCTION_GETNETWORKINFO L"AQQ/Function/GetNetworkInfo"
#define AQQ_FUNCTION_GETNETWORKSTATE L"AQQ/Function/GetNetworkState"
#define AQQ_FUNCTION_CONVERTTOXML L"AQQ/Function/ConvertToXML"
#define AQQ_FUNCTION_GETSTATEPNG_INDEX L"AQQ/Function/GetStatePNG/Index"
#define AQQ_FUNCTION_GETSTATEPNG_FILEPATH L"AQQ/Function/GetStatePNG/FilePath"
#define AQQ_FUNCTION_GETPNG_FILEPATH L"AQQ/Function/GetPNG/FilePath"
#define AQQ_FUNCTION_GETPNGHD_FILEPATH L"AQQ/Function/GetPNGHD/FilePath"
#define AQQ_FUNCTION_SHOWMESSAGE L"AQQ/Function/ShowMessage"
#define AQQ_FUNCTION_STATETOSTR L"AQQ/Function/StateToStr"
#define AQQ_FUNCTION_LOG L"AQQ/Function/Log"
#define AQQ_FUNCTION_SHOWINFO L"AQQ/Function/ShowInfo"
#define AQQ_FUNCTION_GETSTARTCOUNT L"AQQ/Function/GetStartCount"
#define AQQ_FUNCTION_FETCHSETUP L"AQQ/Function/FetchSetup"
#define AQQ_FUNCTION_SAVESETUP L"AQQ/Function/SaveSetup"
#define AQQ_FUNCTION_REFRESHSETUP L"AQQ/Function/RefreshSetup"
#define AQQ_FUNCTION_SILENTUPDATECHECK L"AQQ/Function/SilentUpdateCheck"
#define AQQ_FUNCTION_SSLHANDLE L"AQQ/Function/SSLHandle"
#define AQQ_FUNCTION_SSLLIBHANDLE L"AQQ/Function/SSLLibHandle"
#define AQQ_FUNCTION_LOADLASTCONV L"AQQ/Function/LoadLastConv"
#define AQQ_FUNCTION_PROCESSMESSAGES L"AQQ/Function/ProcessMessages"
#define AQQ_FUNCTION_NORMALIZE L"AQQ/Function/Normalize"
#define AQQ_FUNCTION_DEFAULTNICK L"AQQ/Function/DefaultNick"
#define AQQ_FUNCTION_URLEX L"AQQ/Function/URLEx"
#define AQQ_FUNCTION_URLPOST L"AQQ/Function/URLPost"
#define AQQ_FUNCTION_URLGET L"AQQ/Function/URLGet"
#define AQQ_FUNCTION_INI_CREATE L"AQQ/Function/INI/Create"
#define AQQ_FUNCTION_INI_FREE L"AQQ/Function/INI/Free"
#define AQQ_FUNCTION_INI_READSTRING L"AQQ/Function/INI/ReadString"
#define AQQ_FUNCTION_INI_WRITESTRING L"AQQ/Function/INI/WriteString"
#define AQQ_FUNCTION_FINDFILES L"AQQ/Function/FindFiles"
#define AQQ_FUNCTION_SAVERESOURCE L"AQQ/Function/SaveResource"
#define AQQ_FUNCTION_INTTOSTR L"AQQ/Function/IntToStr"
#define AQQ_FUNCTION_EXCLUDETRAILINGPATHDELIMITER L"AQQ/Function/ExcludeTrailingPathDelimiter"
#define AQQ_FUNCTION_EXTRACTFILENAME L"AQQ/Function/ExtractFilename"
#define AQQ_FUNCTION_FORCEDIRECTORIES L"AQQ/Function/ForceDirectories"
#define AQQ_FUNCTION_LASTDELIMITER L"AQQ/Function/LastDelimiter"
#define AQQ_FUNCTION_FILEEXISTS L"AQQ/Function/FileExists"
#define AQQ_FUNCTION_STRTOINTDEF L"AQQ/Function/StrToIntDef"
#define AQQ_FUNCTION_QUOTEDSTR L"AQQ/Function/QuotedStr"
#define AQQ_FUNCTION_SHA1 L"AQQ/Function/Sha1"
#define AQQ_FUNCTION_SAY L"AQQ/Function/Say"
#define AQQ_FUNCTION_BASE64 L"AQQ/Function/Base64"
#define AQQ_FUNCTION_ISVERSIONHIGHER L"AQQ/Function/IsVersionHigher"
#define AQQ_FUNCTION_GETLANGCODE L"AQQ/Function/GetLangCode"

//CONSTANTS-------------------------------------------------------------------

//##001 - Account Events
#define ACCOUNT_EVENT_DEFAULT 0
#define ACCOUNT_EVENT_NEW 1
#define ACCOUNT_EVENT_EDIT 2
#define ACCOUNT_EVENT_DELETE 3
#define ACCOUNT_EVENT_CHANGEPASS 4

//##002 - System Function
#define SYS_FUNCTION_SEARCHONLIST 1
#define SYS_FUNCTION_ANTISPIM_LEN 2
#define SYS_FUNCTION_TASKBARPEN 3
#define SYS_FUNCTION_CLOSEBTN 4
#define SYS_FUNCTION_MSGCOUNTER 5
#define SYS_FUNCTION_SKINSYSDLG 6

//##003 - Tabs
#define TAB_JABBER 1
#define TAB_SMS 2
#define TAB_MULTICHAT 3
#define TAB_NEWS 4

//##004
#define SETNOTE_ABORT 1
#define SETNOTE_STATE 2
#define SETNOTE_JID 3
#define SETNOTE_CHECK 4

//##005
#define CHATMODE_NORMAL 0
#define CHATMODE_SIMPLE 1

//##006
#define ROLE_VISITOR L"visitor"
#define ROLE_MODERATOR L"moderator"
#define ROLE_PARTICIPANT L"participant"
#define ROLE_OBSERVER L"none"

//##007
#define AFFILIATION_ADMIN L"admin"
#define AFFILIATION_OUTCAST L"outcast"
#define AFFILIATION_MEMBER L"member"
#define AFFILIATION_OWNER L"owner"
#define AFFILIATION_NONE L"none"

//##008 - Connections state
#define CONNSTATE_DISCONNECTED 1
#define CONNSTATE_CONNECTING 2
#define CONNSTATE_CONNECTED 3

//##009
#define TOOLTIP_EVENT_TITLE 0
#define TOOLTIP_EVENT_DATA 1
#define TOOLTIP_EVENT_STATUS 2
#define TOOLTIP_EVENT_AUTH 3
#define TOOLTIP_EVENT_ACTIVITY 4

//##010
#define SM_INFO 0
#define SM_WARN 1
#define SM_QUESTION 2

//##011
#define WINDOW_STATUS_NONE 0
#define WINDOW_STATUS_SET 1
#define WINDOW_STATUS_SETEXIT 2

//##012
#define AQQ_CACHE_ITEM L"AQQ_CACHE_ITEM"
#define AQQ_CACHE_GHOSTITEM L"AQQ_CACHE_GHOSTITEM"

//##013
#define AQQ_QUERY_DELETE 1
#define AQQ_QUERY_MESSAGE 2
#define AQQ_QUERY_SENDFILE 3
#define AQQ_QUERY_AUTHREQUEST 4
#define AQQ_QUERY_SENDPIC 5
#define AQQ_QUERY_AUTH 6
#define AQQ_QUERY_CANCELAUTH 7
#define AQQ_QUERY_SMS 8
#define AQQ_QUERY_VCARD 9
#define AQQ_QUERY_ARCHIVE 10
#define AQQ_QUERY_NETWORK 11
#define AQQ_QUERY_HAVEVCARD 12
#define AQQ_QUERY_ATTENTION 13
#define AQQ_QUERY_NETWORKSTATE 14

//##014
#define AQQ_QUERY_STATE 15
#define AQQ_QUERY_NOTE 16
#define AQQ_QUERY_ONLINE 17
#define AQQ_QUERY_FFC 18
#define AQQ_QUERY_AWAY 19
#define AQQ_QUERY_XA 20
#define AQQ_QUERY_DND 21
#define AQQ_QUERY_OFFLINE 22

//##015
#define CONTACT_UPDATE_OFFLINE -1
#define CONTACT_UPDATE_NORMAL 0
#define CONTACT_UPDATE_NOOFFLINE 1
#define CONTACT_UPDATE_ONLINE 2
#define CONTACT_UPDATE_ONLYSTATUS 3

//##016
#define CONTACT_OFFLINE 0
#define CONTACT_ONLINE 1
#define CONTACT_FFC 2
#define CONTACT_AWAY 3
#define CONTACT_NA 4
#define CONTACT_DND 5
#define CONTACT_INV 6
#define CONTACT_NULL 7

//##017
#define DEBUG_XMLIN 0
#define DEBUG_XMLOUT 1

//##018
#define ONCHECK_COPYTO 1
#define ONCHECK_DELETE 2
#define ONCHECK_MOVETO 3
#define ONCHECK_CHANGENAME 4
#define ONCHECK_SENDMESSAGE 5
#define ONCHECK_SENDIMAGE 6
#define ONCHECK_SETGROUPS 7
#define ONCHECK_VCARD 8

//##019
#define CHAT_NONE 0
#define CHAT_ACTIVE 1
#define CHAT_COMPOSING 2
#define CHAT_GONE 3
#define CHAT_INACTIVE 4
#define CHAT_PAUSED 5

//##020
#define SMS_STATUS_FAILED 0
#define SMS_STATUS_OK 1
#define SMS_STATUS_DELIVERED 2
#define SMS_STATUS_NOTDELIVERED 3

//##021
#define SMS_SEND_OK 1
#define SMS_SEND_FAILED 2
#define SMS_SEND_FAILED_SET 3
#define SMS_SEND_FAILED_AUTH 4
#define SMS_SEND_FAILED_CONNECT 5
#define SMS_SEND_FAILED_LIMIT 6
#define SMS_SEND_FAILED_TOKEN 7
#define SMS_SEND_FAILED_NOSUPPORT 8
#define SMS_SEND_FAILED_UNKNOWN 9
#define SMS_SEND_OK_SILENT 10
#define SMS_SEND_OK_SILENT_NOENABLE 11
#define SMS_SEND_FAILED_FILTER 12
#define SMS_SEND_FAILED_TOOLONG 13
#define SMS_SEND_FAILED_ABORTED 14

//##022
#define SOUND_FIRSTIN 0
#define SOUND_IN 1
#define SOUND_OUT 2
#define SOUND_STATUS 3
#define SOUND_TRANSFER 4
#define SOUND_ENDTRANSFER 5
#define SOUND_LOCK 6
#define SOUND_HELP 7
#define SOUND_CLOSEHELP 8
#define SOUND_CHATIN 9
#define SOUND_CHATOUT 10
#define SOUND_ATTENTION 11
#define SOUND_CALLIN 12
#define SOUND_CALLEND 13
#define SOUND_INFOBOX 14
#define SOUND_POINTS 15
#define SOUND_AUTH 16
#define SOUND_NEWS 17
#define SOUND_CLICK 18

//##023
#define IMP_TYPE_EXPORT 0
#define IMP_TYPE_IMPORT 1
#define IMP_TYPE_OTHER 2

//##024
#define ALIGN_TOP 0
#define ALIGN_BOTTOM 1
#define ALIGN_LEFT 2
#define ALIGN_RIGHT 3
#define ALIGN_CLIENT 4
#define ALIGN_TOWINDOW 5

//##025
#define MSGKIND_CHAT 0
#define MSGKIND_GROUPCHAT 1
#define MSGKIND_RTT 2

//##026
#define TRANSFER_DECLINE 0
#define TRANSFER_ACCEPT 1
#define TRANSFER_CONNECTING 2
#define TRANSFER_ACTIVE 3
#define TRANSFER_DISCONNECT 4
#define TRANSFER_FINISHED 5
#define TRANSFER_PAUSED 6
#define TRANSFER_ABORTED 7

//##027
#define WINDOW_EVENT_CREATE 1
#define WINDOW_EVENT_CLOSE 2

//##028
#define SUB_BOTH 0
#define SUB_NONE 1
#define SUB_FROM 2
#define SUB_TO 3
#define SUB_REMOVE 4
#define SUB_NONEASK 5
#define SUB_FROMASK 6

//##029
#define SOCKS_5 0
#define SOCKS_4A 1
#define SOCKS_4 2

//##030
#define MB_LEFT 0
#define MB_RIGHT 1
#define MB_DBLCLICK 2

//##031
#define CONTROL_ACTION_CREATE 0
#define CONTROL_ACTION_DESTROY 1
#define CONTROL_ACTION_SET 2
#define CONTROL_ACTION_GET 3
#define CONTROL_ACTION_SETFOCUS 4

//##032
#define MODALRES_NONE 0
#define MODALRES_OK 1
#define MODALRES_CANCEL 2

//STRUCTURES-----------------------------------------------------------------

enum THintEvent {
 theAuth,
 theTitle,
 theData,
 theStatus,
 theActivity
};

enum TMiniEvent {
 tmeDeleted,
 tmeStatus,
 tmePseudoStatus,
 tmePseudoMsg,
 tmeMsg,
 tmePseudoMsgCap,
 tmeMsgCap,
 tmeInfo,
 tmeAction,
 tmeAbuse,
 tmeVoip
};

enum TAddonType {
 tatUnCheck,
 tatUnknown,
 tatVisualStyle,
 tatVisualStylePatch,
 tatSmileys,
 tatPlugin
};

typedef struct TPluginChatPrep
{
 int cbSize;
 int UserIdx;
 wchar_t* JID;
 wchar_t* Channel;
 bool CreateNew;
 bool Fast;
} TPluginChatPrep;
typedef
 TPluginChatPrep* PPluginChatPrep;

typedef struct TPluginChatPresence
{
 int cbSize;
 int UserIdx;
 wchar_t* JID;
 wchar_t* RealJID;
 wchar_t* Affiliation;
 wchar_t* Role;
 bool Offline;
 wchar_t* Nick;
 bool Kicked;
 bool Banned;
 wchar_t* Ver;
 wchar_t* JIDToShow;
} TPluginChatPresence;
typedef
 TPluginChatPresence* PPluginChatPresence;

typedef struct TPluginChatOpen
{
 int cbSize;
 wchar_t* JID;
 int UserIdx;
 wchar_t* Channel;
 wchar_t* Nick;
 bool NewWindow;
 bool IsNewMsg;
 bool Priority;
 wchar_t* OriginJID;
 int ImageIndex;
 bool AutoAccept;
 unsigned char ChatMode;
} TPluginChatOpen;
typedef
 TPluginChatOpen* PPluginChatOpen;

typedef struct TPluginHook
{
 wchar_t* HookName;
 WPARAM wParam;
 LPARAM lParam;
} TPluginHook;
typedef
 TPluginHook* PPluginHook;

typedef struct TSaveSetup
{
 wchar_t* Section;
 wchar_t* Ident;
 wchar_t* Value;
} TSaveSetup;
typedef
 TSaveSetup* PSaveSetup;

typedef struct TPluginSong
{
 wchar_t* Title;
 int Position;
 int Length;
} TPluginSong;
typedef
 TPluginSong* PPluginSong;

typedef struct TPluginAddForm
{
 int UserIdx;
 wchar_t* JID;
 wchar_t* Nick;
 wchar_t* Agent;
 bool Modal;
 bool Custom;
} TPluginAddForm;
typedef
 TPluginAddForm* PPluginAddForm;

typedef struct TPluginShowInfo
{
 int cbSize;
 TMiniEvent Event;
 wchar_t* Text;
 wchar_t* ImagePath;
 int TimeOut;
 wchar_t* ActionID;
 unsigned int Tick;
} TPluginShowInfo;
typedef
 TPluginShowInfo* PPluginShowInfo;

typedef struct TPluginToolTipItem
{
 int cbSize;
 unsigned int Tick;
 int Event;
 wchar_t* Text;
 wchar_t* ImagePath;
 wchar_t* ActionID;
 int Y1;
 int Y2;
 int TimeOut;
 int Flag;
} TPluginToolTipItem;
typedef
 TPluginToolTipItem* PPluginToolTipItem;

typedef struct TPluginToolTipID
{
 int cbSize;
 wchar_t* ID;
 wchar_t* Name;
} TPluginToolTipID;
typedef
 TPluginToolTipID* PPluginToolTipID;

typedef struct TPluginSMSResult
{
 int cbSize;
 wchar_t* ID;
 int Result;
} TPluginSMSResult;
typedef
 TPluginSMSResult* PPluginSMSResult;

typedef struct TPluginXMLChunk
{
 int cbSize;
 wchar_t* ID;
 wchar_t* From;
 wchar_t* XML;
 int UserIdx;
} TPluginXMLChunk;
typedef
 TPluginXMLChunk* PPluginXMLChunk;

typedef struct TPluginContactSimpleInfo
{
 int cbSize;
 wchar_t* JID;
 wchar_t* First;
 wchar_t* Last;
 wchar_t* Nick;
 wchar_t* CellPhone;
 wchar_t* Phone;
 wchar_t* Mail;
} TPluginContactSimpleInfo;
typedef
 TPluginContactSimpleInfo* PPluginContactSimpleInfo;

typedef struct TPluginItemDescriber
{
 int cbSize;
 unsigned int FormHandle;
 wchar_t* ParentName;
 wchar_t* Name;
} TPluginItemDescriber;
typedef
 TPluginItemDescriber* PPluginItemDescriber;

typedef struct TPluginPopUp
{
 int cbSize;
 wchar_t* Name;
 unsigned int ParentHandle;
 unsigned int Handle;
} TPluginPopUp;
typedef
 TPluginPopUp* PPluginPopUp;

typedef struct TPluginTriple
{
 int cbSize;
 unsigned int Handle1;
 unsigned int Handle2;
 unsigned int Handle3;
 int Param1;
 int Param2;
} TPluginTriple;
typedef
 TPluginTriple* PPluginTriple;

typedef struct TPluginError
{
 int cbSize;
 wchar_t* ID;
 wchar_t* Desc;
 wchar_t* LangID;
 wchar_t* ErrorCode;
} TPluginError;
typedef
 TPluginError* PPluginError;

typedef struct TPluginTransfer
{
 int cbSize;
 wchar_t* ID;
 wchar_t* FileName;
 wchar_t* Location;
 int Status;
 wchar_t* TextInfo;
 __int64 FileSize;
 __int64 Position;
 __int64 LastDataSize;
} TPluginTransfer;
typedef
 TPluginTransfer* PPluginTransfer;

typedef struct TPluginTransferOld
{
 int cbSize;
 wchar_t* ID;
 wchar_t* FileName;
 wchar_t* Location;
 int Status;
 wchar_t* TextInfo;
 unsigned int FileSize;
 unsigned int Position;
 unsigned int LastDataSize;
} TPluginTransferOld;
typedef
 TPluginTransferOld* PPluginTransferOld;

typedef struct TPluginWindowEvent
{
 int cbSize;
 wchar_t* ClassName;
 unsigned int Handle;
 int WindowEvent;
} TPluginWindowEvent;
typedef
 TPluginWindowEvent* PPluginWindowEvent;

typedef struct TPluginChatState
{
 int cbSize;
 wchar_t* Text;
 int Length;
 int SelStart;
 int SelLength;
 unsigned int ParentHandle;
 unsigned int Handle;
 int ChatState;
} TPluginChatState;
typedef
 TPluginChatState* PPluginChatState;

typedef struct TPluginWebItem
{
 int cbSize;
 wchar_t* ID;
 wchar_t* Text;
} TPluginWebItem;
typedef
 TPluginWebItem* PPluginWebItem;

typedef struct TPluginSmallInfo
{
 int cbSize;
 wchar_t* Text;
} TPluginSmallInfo;
typedef
 TPluginSmallInfo* PPluginSmallInfo;

typedef struct TPluginWebBeforeNavEvent
{
 int cbSize;
 unsigned int Handle;
 wchar_t* URL;
 wchar_t* Flags;
 wchar_t* TargetFrameName;
 wchar_t* PostData;
 wchar_t* Headers;
} TPluginWebBeforeNavEvent;
typedef
 TPluginWebBeforeNavEvent* PPluginWebBeforeNavEvent;

typedef struct TPluginWebBrowser
{
 int cbSize;
 unsigned int Handle;
 int Top;
 int Left;
 int Width;
 int Height;
 int Align;
 bool RegisterAsDropTarget;
 bool SetVisible;
 bool SetEnabled;
} TPluginWebBrowser;
typedef
 TPluginWebBrowser* PPluginWebBrowser;

typedef struct TPluginDebugInfo
{
 int cbSize;
 wchar_t* JID;
 wchar_t* XML;
 unsigned char Mode;
} TPluginDebugInfo;
typedef
 TPluginDebugInfo* PPluginDebugInfo;

typedef struct TPluginMaxStatus
{
 int cbSize;
 int IconIndex;
 wchar_t* Name;
 int Max;
} TPluginMaxStatus;
typedef
 TPluginMaxStatus* PPluginMaxStatus;

typedef struct TPluginProxy
{
 int cbSize;
 bool ProxyEnabled;
 wchar_t* ProxyServer;
 int ProxyPort;
 int ProxyType;
 bool ProxyAuth;
 wchar_t* ProxyLogin;
 wchar_t* ProxyPass;
} TPluginProxy;
typedef
 TPluginProxy* PPluginProxy;

typedef struct TPluginImpExp
{
 int cbSize;
 int ImportType;
 wchar_t* Name;
 wchar_t* Service;
 int IconIndex;
} TPluginImpExp;
typedef
 TPluginImpExp* PPluginImpExp;

typedef struct TPluginAutomation
{
 int cbsize;
 int Flags;
 int NewState;
 double LastActive;
} TPluginAutomation;
typedef
 TPluginAutomation* PPluginAutomation;

typedef struct TPluginStateChange
{
 int cbSize;
 int OldState;
 int NewState;
 wchar_t* Status;
 bool ByHand;
 int UserIdx;
 wchar_t* JID;
 bool Force;
 wchar_t* Server;
 bool Authorized;
 bool FromPlugin;
 wchar_t* Resource;
} TPluginStateChange;
typedef
 TPluginStateChange* PPluginStateChange;

typedef struct TPluginSMS
{
 int cbSize;
 wchar_t* CellPhone;
 wchar_t* Msg;
 wchar_t* Sign;
 int GateID;
} TPluginSMS;
typedef
 TPluginSMS* PPluginSMS;

typedef struct TPluginTwoFlagParams
{
 int cbSize;
 wchar_t* Param1;
 wchar_t* Param2;
 int Flag1;
 int Flag2;
} TPluginTwoFlagParams;
typedef
 TPluginTwoFlagParams* PPluginTwoFlagParams;

typedef struct TPluginAddUser
{
 int cbSize;
 wchar_t* UID;
 wchar_t* Server;
 wchar_t* Nick;
 wchar_t* Group;
 wchar_t* Reason;
 wchar_t* Service;
} TPluginAddUser;
typedef
 TPluginAddUser* PPluginAddUser;

typedef struct TPluginSMSGate
{
 int cbSize;
 wchar_t* Name;
 wchar_t* Prompt;
 bool IsConfig;
 int MaxLength;
 int SignMaxLength;
} TPluginSMSGate;
typedef
 TPluginSMSGate* PPluginSMSGate;

typedef struct TPluginAgent
{
 int cbSize;
 wchar_t* JID;
 wchar_t* Name;
 wchar_t* Prompt;
 bool Transport;
 bool Search;
 bool GroupChat;
 bool Agents;
 wchar_t* Service;
 bool CanRegister;
 wchar_t* Description;
 bool RequiredID;
 int IconIndex;
 wchar_t* PluginAccountName;
} TPluginAgent;
typedef
 TPluginAgent* PPluginAgent;

 typedef struct TPluginAvatar
{
 wchar_t* FileName;
 bool XEPEmpty;
 bool SilentMode;
 wchar_t* JID;
} TPluginAvatar;
typedef
 TPluginAvatar* PPluginAvatar;

typedef struct TPluginMessage
{
 int cbSize;
 wchar_t* JID;
 double Date;
 int ChatState;
 wchar_t* Body;
 bool Offline;
 wchar_t* DefaultNick;
 bool Store;
 unsigned char Kind;
 bool ShowAsOutgoing;
} TPluginMessage;
typedef
 TPluginMessage* PPluginMessage;

typedef struct TPluginMsgPic
{
 int cbSize;
 wchar_t* FilePath;
 wchar_t* Description;
 wchar_t* ID;
 } TPluginMsgPic;
typedef
 TPluginMsgPic* PPluginMsgPic;

typedef struct TPluginFileTransfer
{
 int cbSize;
 wchar_t* FilePath;
 wchar_t* Description;
 wchar_t* ID;
 } TPluginFileTransfer;
typedef
 TPluginFileTransfer* PPluginFileTransfer;
 
typedef struct TPluginMicroMsg
{
 int cbSize;
 wchar_t* Msg;
 bool SaveToArchive;
 } TPluginMicroMsg;
typedef
 TPluginMicroMsg* PPluginMicroMsg; 

typedef struct TPluginInfo
{
 int cbSize;
 wchar_t* ShortName;
 DWORD Version;
 wchar_t* Description;
 wchar_t* Author;
 wchar_t* AuthorMail;
 wchar_t* Copyright;
 wchar_t* Homepage;
 unsigned char Flag;
 int ReplaceDefaultModule;
} TPluginInfo;
typedef
 TPluginInfo* PPluginInfo;

typedef struct TPluginActionEdit
{
 int cbSize;
 wchar_t* pszName;
 wchar_t* Caption;
 wchar_t* Hint;
 bool Enabled;
 bool Visible;
 int IconIndex;
 bool Checked;
} TPluginActionEdit;
typedef
 TPluginActionEdit* PPluginActionEdit;

typedef struct TPluginAccountInfo
{
 int cbSize;
 wchar_t* Name;
 wchar_t* JID;
 wchar_t* Status;
 int ShowType;
 int IconIndex;
} TPluginAccountInfo;
typedef
 TPluginAccountInfo* PPluginAccountInfo;

typedef struct TPluginWindowStatus
{
 int cbSize;
 int Status;
 wchar_t* TextStatus;
 bool AllAccounts;
 bool OnlyNote;
} TPluginWindowStatus;
typedef
 TPluginWindowStatus* PPluginWindowStatus;

typedef struct TPluginAction
{
 int cbSize;
 wchar_t* Action;
 wchar_t* pszName;
 wchar_t* pszCaption;
 DWORD Flags;
 int Position;
 int IconIndex;
 wchar_t* pszService;
 wchar_t* pszPopupName;
 int PopupPosition;
 DWORD hotKey;
 wchar_t* pszContactOwner;
 int GroupIndex;
 bool Grouped;
 bool AutoCheck;
 bool Checked;
 unsigned int Handle;
 wchar_t* ShortCut;
 wchar_t* Hint;
 wchar_t* PositionAfter;
} TPluginAction;
typedef
 TPluginAction* PPluginAction;
 
typedef struct TPluginHTTPRequest
{ 
 int cbSize;
 unsigned char ProtocolVersion;
 UnicodeString Method;
 UnicodeString URL;
 bool AllowCookies;
 bool ForceEncodeParams;
 bool HandleRedirects;
 wchar_t* HeaderUserAgent;
 wchar_t* HeaderAccept;
 wchar_t* HeaderAcceptLanguage;
 wchar_t* HeaderAcceptEncoding;
 wchar_t* HeaderAcceptCharset;
 wchar_t* HeaderContentType;
 wchar_t* HeaderReferer;
 bool ResultLocation;
 wchar_t* CustomHeaders;
 wchar_t* HTTPPayLoad;  
 bool BasicAuth;
 wchar_t* BasicAuthLogin;
 wchar_t* BasicAuthPass;
} TPluginHTTPRequest;
typedef
 TPluginHTTPRequest* PPluginHTTPRequest;

typedef struct TPluginAccountEvents
{
 int cbSize;
 wchar_t* DisplayName;
 int IconIndex;
 bool EventNew;
 bool EventEdit;
 bool EventDelete;
 bool EventPassChange;
 bool EventDefault;
} TPluginAccountEvents;
typedef
 TPluginAccountEvents* PPluginAccountEvents;

typedef struct TPluginContact
{
 int cbSize;
 wchar_t* JID;
 wchar_t* Nick;
 wchar_t* Resource;
 wchar_t* Groups;
 int State;
 wchar_t* Status;
 bool Temporary;
 bool FromPlugin;
 int UserIdx;
 unsigned char Subscription;
 bool IsChat;
} TPluginContact;
typedef
 TPluginContact* PPluginContact;

typedef struct TPluginNewsData
{
 wchar_t* Kind;
 wchar_t* Title;
 wchar_t* ID;
 bool Active;
 int ImageIndex;
} TPluginNewsData;
typedef
 TPluginNewsData* PPluginNewsData;

typedef struct TPluginNewsItem
{
 TDateTime Date;
 wchar_t* News;
 wchar_t* Title;
 wchar_t* Source;
 int ParentIndex;
} TPluginNewsItem;
typedef
 TPluginNewsItem* PPluginNewsItem;
 
typedef struct TPluginForm
{
 int cbSize;
 int Handle;
 wchar_t* Name;
 wchar_t* Caption;
 int Width;
 int Height;
} TPluginForm;
typedef
 TPluginForm* PPluginForm;

typedef struct TPluginFont
{
 bool UseCustomFontSize;
 int CustomFontSize;
 bool UseCustomFontFace;
 wchar_t* CustomFontFace;
 bool UseCustomFontColor;
 int CustomFontColor;
 bool FontBold;
 bool FontUnderLine;
} TPluginFont;
typedef
 TPluginFont* PPluginFont;
 
typedef struct TPluginRect
{
 int Left;
 int Top;
 int Right;
 int Bottom;
} TPluginRect;
typedef
 TPluginRect* PPluginRect;
 
typedef struct TPluginControl
{
 int cbSize;
 int Handle;
 int FormParentHandle;
 wchar_t* ClassName;
 wchar_t* Name;
 wchar_t* Text;
 wchar_t* Caption;
 TPluginFont Font;
 int ModalResult;
 bool Checked;
 bool Enabled;
 TPluginRect BoundsRect;
 bool AutoSize;
 bool PassField;
} TPluginControl;
typedef
 TPluginControl* PPluginControl;
 
typedef struct TPluginExecMsg
{
 wchar_t* JID;
 int UserIdx;
 bool ActionSwitchTo;
 bool ActionCloseWindow;
 bool ActionTabIndex;
 bool ActionTabWasClosed;
 bool IsPriority;
 bool IsFromPlugin;
} TPluginExecMsg;
typedef
 TPluginExecMsg* PPluginExecMsg;
 
typedef struct TPluginPrivacyItem
{
 unsigned char ItemType;
 wchar_t* Value;
 unsigned char Msg;
 unsigned char PresIn;
 unsigned char PresOut;
 unsigned char IQ;
} TPluginPrivacyItem;
typedef
 TPluginPrivacyItem* PPluginPrivacyItem;
 
typedef INT_PTR (__stdcall *TAQQHook)(WPARAM wParam, LPARAM lParam);
typedef TAQQHook* PAQQHook;

typedef INT_PTR (__stdcall *TAQQService)(WPARAM wParam,LPARAM lParam);
typedef TAQQService* PAQQService;

typedef struct TPluginLink
{
 wchar_t* Path;
 HANDLE (__stdcall *CreateHookableEvent)(wchar_t* Name);
 INT_PTR (__stdcall *DestroyHookableEvent)(HANDLE hEvent);
 INT_PTR (__stdcall *NotifyEventHooks)(HANDLE hEvent, WPARAM wParam, LPARAM lParam);
 HANDLE (__stdcall *HookEvent)(wchar_t* Name, TAQQHook HookProc);
 HANDLE (__stdcall *HookEventMessage)(wchar_t* Name, HWND Handle, unsigned int Msg);
 int (__stdcall *UnhookEvent)(HANDLE hHook);
 HANDLE (__stdcall *CreateServiceFunction)(wchar_t* Name, TAQQService ServiceProc);
 void* CreateTransientServiceFunction;
 INT_PTR (__stdcall *DestroyServiceFunction)(HANDLE hService);
 INT_PTR (__stdcall *CallService)(wchar_t* Name, WPARAM wParam, LPARAM lParam);
 INT_PTR (__stdcall *ServiceExists)(wchar_t* Name);
} TPluginLink;
typedef
 TPluginLink* PPluginLink;


//OTHER----------------------------------------------------------------------

#define CALLSERVICE_NOTFOUND 0x80000000
#define MAXMODULELABELLENGTH 64

#define PLUGIN_MAKE_VERSION(a,b,c,d) ((((a)&0xFF)<<24)|(((b)&0xFF)<<16)|(((c)&0xFF)<<8)|((d)&0xFF))
#define PLUGIN_COMPARE_VERSION(a,b) (((DWORD)(a)<(DWORD)(b))?-1:((DWORD)(a)>(DWORD)(b))?1:0)

#endif