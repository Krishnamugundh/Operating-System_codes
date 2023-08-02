#Write a shell program to addition of two numbers.
#Code:
read a
read b
sum=$(( $a + $b ))
echo "Sum is: $sum"

#2.) Write a shell program to largest of numbers.
#Code:
read num1
read num2
read num3
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
echo largest num:$num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
echo largest num:$num2
else
echo largest num:$num3
fi


#3.) Write a shell program for unix case command.
#Code:
echo "Please talk to me ..."
while :
do
read INPUT_STRING
case $INPUT_STRING in
hello)
echo "Hello yourself!";;
bye)
echo "See you again!"
break;;
*)
echo "Sorry, I don't understand";;
  esac
done
echo
echo "That's all folks!"


#4.) Write a shell program to find the factorial of a number.
#Code:
echo "Enter a number"
read num                
fact=1
while [ $num -gt 1 ]  
do
fact=$((fact * num))  
num=$((num - 1))     
done
echo $fact

#5.) Write a shell program to find fibinocii digit of numbers.3
echo "How many numbers do you want of Fibonacci series ?"
read total
x=0
y=1
i=2
echo "Fibonacci Series up to $total terms :: "
echo "$x"
echo "$y"
while [ $i -lt $total ]
do
i=`expr $i + 1 `
z=`expr $x + $y `
echo "$z"
x=$y
y=$z
done



#6.) Write a shell program to find largest digit of number.
#Code:
echo "Enter Size(N) of the digit"
read N
i=1
max=0
echo "Enter digits"
while [ $i -le $N ]
do
read num
if [ $i -eq 1 ]
then
max=$num
else
if [ $num -gt $max ]
then
max=$num
fi
fi
i=$((i + 1))  #increment i by 1
done
echo the largest digit:$max


#7.) Write a shell program to find reverse digit of numbers.
#Code:
echo enter n
read n
num=0
while [ $n -gt 0 ]
do
num=$(expr $num \* 10)
k=$(expr $n % 10)
num=$(expr $num + $k)
n=$(expr $n / 10)
done
echo number is $num


#8.) WSP for displaying the grade of a student.
#Code:
read a
if [ $a -ge 90 ]
then
echo the grade is S
elif [ $a -ge 80 ]
then
echo the grade is A
elif [ $a -ge 70 ]
then
echo the grade is B
elif [ $a -ge 60 ]
then
echo the grade is C
elif [ $a -ge 50 ]
then
echo the grade is D
elif [ $a -ge 40 ]
then
echo the grade is E
else
echo the student is fail
fi

#9.) WSP for  sum of n numbers.
#Code:
read n
i=0
while [ $i -lt $n ]
do
c=$(($c+$i))
i=$(($i+1))
done
echo The sum of n numbers is:$c


#10.) WSP  for  finding the largest number.
#Code:
read a
read b
read c
if [ $a -gt $b ] && [ $b -gt $c ]
then
echo the second largest number:$b
elif [ $b -gt $a ] && [ $a -gt $c ]
then
echo the second largest number:$a
elif  [ $c -gt $b ] && [ $c -gt $a ]
then
echo the second largest number:$c
fi
