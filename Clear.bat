
del /s /q *.ncb
del /s /q .\Release\*.exp
;del /s /q .\Release\*.lib
del /s /q .\Release\*.pdb
del /s /q .\Release\*.log

rmdir /s /q .\debug\
rmdir /s /q .\Test\debug\
rmdir /s /q .\Test\Release\
rmdir /s /q .\ThomasZhuUtilityMFC\debug\
rmdir /s /q .\ThomasZhuUtilityMFC\Release\
rmdir /s /q .\ThomasZhuUtilityWin32\debug\
rmdir /s /q .\ThomasZhuUtilityWin32\Release\

copy .\release\*.bin .\debug /b
copy .\release\*.ini .\debug /b
