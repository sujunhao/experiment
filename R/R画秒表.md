##用R画一个秒表
##然而时间并不精确

x <- seq(0, 2*pi, 0.001)

plot(sin(x), cos(x), type='l')

points(0, 0, cex=1.5)

n = 60

for (t in n:1){
	i = t+n/4
	arrows(0, 0, cos(2*pi/n*i), sin(2*pi/n*i), , col='red')
	arrows(0, 0, cos(2*pi/n*(i-1)), sin(2*pi/n*(i-1)))
	Sys.sleep(1)
}