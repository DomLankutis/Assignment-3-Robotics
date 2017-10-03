@if (@CodeSection == @Batch) @then


@echo off
echo INITIALISING ARDUINO IDE

rem Use %SendKeys% to send keys to the keyboard buffer
set SendKeys=CScript //nologo //E:JScript "%~F0"

rem Start the other program in the same Window
start main/main.ino

SLEEP 10
%SendKeys% "^u"
echo COMPILING CODE
%SendKeys% "^+m"
echo RUNNING SERIAL MONITOR
SLEEP 6

@end

// JScript section

var WshShell = WScript.CreateObject("WScript.Shell");
WshShell.SendKeys(WScript.Arguments(0));
