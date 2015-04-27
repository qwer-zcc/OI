:loop
cs
F > me.out
bc > bc.out
fc bc.out me.out
if %errorlevel%==0 goto loop
pause
goto loop