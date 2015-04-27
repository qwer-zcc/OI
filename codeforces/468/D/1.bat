:loop
cs
bc > bc.out
D > D.out
fc D.out bc.out
if %errorlevel%==0 goto loop
pause