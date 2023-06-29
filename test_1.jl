
# Quick Newton Method

# xi = 10

# function value1(xi)
#     f(x) = 5 - x^2
#     h = 10^-5
#     der_1(x) = (f(x + h) - f(x)) / h
#     x_n = xi
#     val1 = 1; 

#     for i = 1:10
#         if(der_1(xi) >= 0 )
#             val1 = 5; 
#         end 
#         if(der_1(xi) < 0 )
#             val1 = -5; 
#         end 
#         x_n = xi - f(xi) / val1
#         xi = x_n
#         println(x_n)

#         if abs(f(xi)) <= 10^-5
#             println(val1)

#             break 
#         end
#     end
# end
# value1(xi)

# function NewtonMethod(f,xo,h)
#     f1 = x-> (f.(x+h)-f(x))/h; # approximation of derivative
#     for i in 1:300
#             x_n1 = xo-f.(xo)*(f1.(xo)).^-1

#                 if(abs(f.(xo)) < 10^-5)
#                         display(x_n1)
#                         display(["iterations : ", i])

#                         break;
#                 end
#                 xo = x_n1
#                 display(x_n1)

#     end
# end
# f(x) = 5 - x^2
# xo = 10
# h = 10^-5
# NewtonMethod(f,xo,h)








w = -500000 



function fun1(w)

    x = [0 1 2 3 4]
    y = [0 2 4 6 8]
    y_pred = w*x
    display(y_pred)
    h = 10^-5
    d = sum(y-y_pred); 

    der_d = abs.(y-y_pred)
    display(d)
    display(der_d)
    der_d_1 = (d+h-d)/h
    for j = 1:100 

        d = (sum((-y+w*x))); 
        d1 =  (sum((-y+(w+h)*x))); 
        der_d_1 = (d1-d)/h
        w = w-0.5*d/der_d_1

    
        display(w)

    end 
end 
 
fun1(w)


# CTRL+SHIFT+7- > comment the code
