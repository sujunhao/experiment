#R语言输入与输出

##键盘与显示器

###scan()
```

scan(file = "", what = double(), nmax = -1, n = -1, sep = "",
     quote = if(identical(sep, "\n")) "" else "'\"", dec = ".",
     skip = 0, nlines = 0, na.strings = "NA",
     flush = FALSE, fill = FALSE, strip.white = FALSE,
     quiet = FALSE, blank.lines.skip = TRUE, multi.line = TRUE,
     comment.char = "", allowEscapes = FALSE,
     fileEncoding = "", encoding = "unknown", text, skipNul = FALSE)


##从键盘读
> x <- scan()
1: 123
2: 23
3: 2
4:          ##输入回车介绍
Read 3 items
> x
[1] 123  23   2

##从本地文件读

##本地文件的位置
> getwd()
[1] "C:/Users/PureWeber/Documents"

##读取
> x <- scan('z1.txt')
Read 4 items
> x
[1] 123.0   4.2   5.0   6.0


##读取字符串
> x <- scan(, what='')
1: 123
2: sd
3: 23j
4: 
Read 3 items
> x
[1] "123" "sd"  "23j"

##分割
> scan('z1.txt', what='')
Read 4 items
[1] "123" "asd" "1"   "6"  
> scan('z1.txt', what='', sep='\n')
Read 3 items
[1] "123"   "asd 1" "6"  
```

###readline()
```

readline(prompt = "")

prompt	
the string printed when prompting the user for input. Should usually end with a space " ".

参数为提示字符串


##从键盘中读取整行
> w <- readline('input a number: ')
input a number: 123
> w
[1] "123"
```

###print()和cat()
```
> print(1:3)
[1] 1 2 3
> cat(1:3)
1 2 3
> cat('asd', x)
asd 123 4.25 6
> cat('asd', x, sep='')
asd1234.256
> cat('asd', x, sep=c(',','|'))
asd,123|4.25,6
```

