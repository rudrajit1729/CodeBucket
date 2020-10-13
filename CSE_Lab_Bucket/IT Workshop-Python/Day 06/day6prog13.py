def interest(p, t, a):
    if a >= 65:
        interest = p * t * .12
    else:
        interest = p * t * .10
    return interest
principal = input("Principal:")
time = input("Time:")
age = input("Age:")

print(interest(principal, time, age))
