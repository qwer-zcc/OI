:loop
cs
1 > 1.out
A > A.out
fc 1.out A.out
if %errorlevel%==0 goto loop
pause