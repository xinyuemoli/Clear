#include "ClearLogs.h"
#include "../utils/path.h"
#include "../utils/GetFiles.h"
#include <iostream>

ClearLogCache::ClearLogCache()
{
    paths_ = { L"%ALLUSERSPROFILE%\\Application Data\\Microsoft\\Dr Watson\\*.log",
                L"%ALLUSERSPROFILE%\\Application Data\\Microsoft\\Dr Watson\\user.dmp",
                L"%LocalAppData%\\Microsoft\\Windows\\WER\\ReportArchive\\*",
                L"%LocalAppData%\\Microsoft\\Windows\\WER\\ReportQueue\\*",
                L"%programdata%\\Microsoft\\Windows\\WER\\ReportArchive\\*",
                L"%programdata%\\Microsoft\\Windows\\WER\\ReportQueue\\*",
                L"%localappdata%\\Microsoft\\Internet Explorer\\brndlog.bak",
                L"%localappdata%\\Microsoft\\Internet Explorer\\brndlog.txt",
                L"%windir%\\*.log",
                L"%windir%\\imsins.BAK",
                L"%windir%\\OEWABLog.txt",
                L"%windir%\\SchedLgU.txt",
                L"%windir%\\ntbtlog.txt",
                L"%windir%\\setuplog.txt",
                L"%windir%\\REGLOCS.OLD",
                L"%windir%\\Debug\\*.log",
                L"%windir%\\Debug\\Setup\\UpdSh.log",
                L"%windir%\\Debug\\UserMode\\*.log",
                L"%windir%\\Debug\\UserMode\\ChkAcc.bak",
                L"%windir%\\Debug\\UserMode\\userenv.bak",
                L"%windir%\\Microsoft.NET\\Framework\\*\\*.log",
                L"%windir%\\pchealth\\helpctr\\Logs\\hcupdate.log",
                L"%windir%\\security\\logs\\*.log",
                L"%windir%\\security\\logs\\*.old",
                L"%windir%\\SoftwareDistribution\\*.log",
                L"%windir%\\SoftwareDistribution\\DataStore\\Logs\\*",
                L"%windir%\\system32\\TZLog.log",
                L"%windir%\\system32\\config\\systemprofile\\Application Data\\Microsoft\\Internet Explorer\\brndlog.bak",
                L"%windir%\\system32\\config\\systemprofile\\Application Data\\Microsoft\\Internet Explorer\\brndlog.txt",
                L"%windir%\\system32\\LogFiles\\AIT\\AitEventLog.etl.???",
                L"%windir%\\system32\\LogFiles\\Firewall\\pfirewall.log*",
                L"%windir%\\system32\\LogFiles\\Scm\\SCM.EVM*",
                L"%windir%\\system32\\LogFiles\\WMI\\Terminal*.etl",
                L"%windir%\\system32\\LogFiles\\WMI\\RTBackup\\EtwRT.*etl",
                L"%windir%\\system32\\wbem\\Logs\\*.lo_",
                L"%windir%\\system32\\wbem\\Logs\\*.log" };
}

std::wstring ClearLogCache::GetDisplayName()
{
    return std::wstring();
}

std::wstring ClearLogCache::GetDescription()
{
    return std::wstring();
}

void ClearLogCache::Scan(TCallBack callback)
{
    //%ALLUSERSPROFILE%\Microsoft\Windows\WER\ 
    //%windir%%\setup*.log|setup*.old|setuplog.txt|winnt32.log
    //%ProgramData%\Microsoft\Diagnosis\FeedbackArchive\ *.*

    for (int i =0;i < paths_.size();i++)
    {
        std::wstring path = utils::ExpandEnvironmentVariables(paths_[i]);
        utils::FindFiles(path);
    }
}

void ClearLogCache::Purge(std::vector<uint>& vec_clears)
{
}
