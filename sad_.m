clc
clear
syms theta1;

syms theta2;

b2=24;

b3=106;

b1=10.7;

syms theta3;

b4=99.42;

syms theta4;

b5=-10.7;

syms theta5;

c7=74.7;



A1=[cos(theta1), 0, -sin(theta1), b2*cos(theta1);

sin(theta1), 0, cos(theta1), b2*sin(theta1);

0, -1, 0, b1;

0, 0, 0, 1];

A2=[cos(theta2), -sin(theta2), 0, b3*cos(theta2);

sin(theta2), cos(theta2), 0, b3*sin(theta2);

0, 0, 1, 0;

0, 0, 0, 1];

A3=[cos(theta3), -sin(theta3), 0, b4*cos(theta3);

sin(theta3), cos(theta3), 0, b4*sin(theta3);

0, 0, 1, 0;

0, 0, 0, 1];

A4=[cos(theta4), 0, sin(theta4), 0;

sin(theta4), 0, -cos(theta4), 0;

0, 1, 0, b5;

0, 0, 0, 1];

A5=[cos(theta5), -sin(theta5), 0, 0;

sin(theta5), cos(theta5), 0, 0;

0, 0, 1, c7;

0, 0, 0, 1];



 sym AI1=[];
 sym AI2=[];
sym AI3=[];
sym AI4=[];
sym AI5=[];

for i=1:4
   AI1(4,i)=A1(4,i);
   AI2(4,i)=A1(4,i);
   AI3(4,i)=A1(4,i);
   AI4(4,i)=A1(4,i);
    AI5(4,i)=A1(4,i);
    end
for i=1:3
    for j=1:3
        AI1(i,j)=A1(j,i);
        AI2(i,j)=A2(j,i);
        AI3(i,j)=A3(j,i);
        AI4(i,j)=A4(j,i);
        AI5(i,j)=A5(j,i);
    end
end
sum=0;
for j=1:3
    for k=1:3
        sum=sum+AI1(j,k)*A1(k,4);
    end
    AI1(j,4)=-1*sum;
    sum=0;
end
%
for j=1:3
    for k=1:3
        sum=sum+AI2(j,k)*A2(k,4);
    end
    AI2(j,4)=-1*sum;
    sum=0;
end
%
for j=1:3
    for k=1:3
        sum=sum+AI3(j,k)*A3(k,4);
    end
    AI3(j,4)=-1*sum;
    sum=0;
end
%
for j=1:3
    for k=1:3
        sum=sum+AI4(j,k)*A4(k,4);
    end
    AI4(j,4)=-1*sum;
    sum=0;
end
%
for j=1:3
    for k=1:3
        sum=sum+AI5(j,k)*A5(k,4);
    end
    AI5(j,4)=-1*sum;
    sum=0;
end

KNOWN=[1, 0, 0, 229.42;
    0, 1, 0, 10.7;
    0, -1, 1, 85.4;
    0, 0, 0, 1];
known1=AI1*KNOWN;%LHS inverse multiplication

T06=A1*A2*A3*A4*A5;
T06=AI1*A1*A2*A3*A4*A5 ;%first inverse multiplication of RHS
theta1=double((solve(known1(3,4)-T06(3,4),theta1))*180/pi);
theta5=double(subs((solve(known1(3,1)-T06(3,1),theta5)*180/pi),'theta1',theta1));



T06=AI2*AI1*A1*A2*A3*A4*A5;
known1=AI1*AI2*KNOWN;

%theta5=subs((solve(known2(3,4)-T06(3,4),theta5))*180/pi,'theta1',0)

