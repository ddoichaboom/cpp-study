@echo off
REM Engine Build Post-Event: Copy headers, dll, and lib files

REM Copy Engine headers to Reference
xcopy /y .\Engine\Header\*.h .\Reference\Header\

REM Copy Engine.dll to Client Bin
xcopy /y .\Engine\Bin\Engine.dll .\Client\Bin\

REM Copy Engine.dll to Editor Bin
xcopy /y .\Engine\Bin\Engine.dll .\Editor\Bin\

REM Copy Engine.lib to Reference Library
xcopy /y .\Engine\Bin\Engine.lib .\Reference\Library\

echo Engine files copied successfully!
