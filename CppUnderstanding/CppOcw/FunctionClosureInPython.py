def anotherfunc(h):
    a = 1
    def func(): return h + a
    return func

def Test(a):
    print a()

print anotherfunc(10)()
Test( anotherfunc(20) )