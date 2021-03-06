

clc;
close all;
clear all;

theta1=0;d1=10.7;a1=24;alpha1=-pi/2; %parameter link1
theta2=0;d2=0;a2=106;alpha2=0; %parameter link2
theta3=0;d3=0;a3=99.42;alpha3=0; %parameter link3
theta4=0;d4=-10.7;a4=0;alpha4=pi/2; %parameter link4
theta5=0;d5=74.7;a5=0;alpha5=0; %parameter link5

Wx=0;
Wy=0;
Wz=0;

Xc=15;
Yc=15;
Zc=25;
 



deltatheta1=0;deltatheta2=0; deltatheta3=0; deltatheta4=0; deltatheta5=0;%theta1,2,3,4,5 velocity

a=0;b=0;

while a==0
    while b==0
        
        theta1=theta1+deltatheta1/2
        theta2=theta2+deltatheta2/2
        theta3=theta3+deltatheta3/2
        theta4=theta1+deltatheta4/2
        theta5=theta2+deltatheta5/2
       

        T01=DHmatrix(theta1,d1,a1,alpha1);
        T12=DHmatrix(theta2,d2,a2,alpha2);
        T23=DHmatrix(theta3,d3,a3,alpha3);
        T34=DHmatrix(theta4,d4,a4,alpha4);
        T45=DHmatrix(theta5,d5,a5,alpha5);
        
        T01;
        T02=T01*T12;
        T03=T01*T12*T23;
        T04=T01*T12*T23*T34;
        T05=T01*T12*T23*T34*T45
        
         P0=[0 0 0];
         P1=transpose(T01(1:3,4))
         P2=transpose(T02(1:3,4));
         P3=transpose(T03(1:3,4));
         P4=transpose(T04(1:3,4));
         P5=transpose(T05(1:3,4));
        
          
        
        
        j=[0, 0, 0, 0, 0;
           0, 0, 0, 0, 0;
           0, 0, 0, 0, 0;
           0, 0, 0, 0, 0;
           0, 0, 0, 0, 0;
           0, 0, 0, 0, 0];
        
        %jw
        for i=1:3
            jw(i,1)=T01(i,3);
            
        end
        for i=1:3
            jw(i,2)=T02(i,3);
            
        end
        for i=1:3
            jw(i,3)=T03(i,3);
            
        end
        for i=1:3
            jw(i,4)=T04(i,3);
            
        end
        for i=1:3
            jw(i,5)=T05(i,3);
            
        end
        
     
        
        %Jv
        
        O=[0;0;0];
        
        Z0=[0;0;1];
        O3=T03(1:3,4);
        Jv1=cross(Z0,(O3-O));
        
        Z1=T01(1:3,3);      
        O1=T01(1:3,4);
        Jv2=cross(Z1,(O3-O1));
        
        Z2=T02(1:3,3);        
        O2=T02(1:3,4);
        Jv3=cross(Z2,(O3-O2));
        
        Z3=T03(1:3,3);        
        O2=T03(1:3,4);
        Jv4=cross(Z3,(O3-O2));
        
        Z4=T04(1:3,3);        
        O2=T04(1:3,4);
        Jv5=cross(Z4,(O3-O2));
        
        j=[Jv1 Jv2 Jv3 Jv4 Jv5;
            jw];
        
         Xinit=P5(1,1);
         Yinit=P5(1,2);
         Zinit=P5(1,3);
        
         Xend=Xc;
         Yend=Yc;
         Zend=Zc;
         
        Xspeed=(Xend-Xinit);
        Yspeed=(Yend-Yinit);
        Zspeed=(Yend-Yinit);
        
        %Pseudoinverse Jacobian
        thetadot=pinv(j)*[Xspeed;Yspeed;Zspeed;Wx;Wy;Wz];
        dis_error=sqrt(Xend^2+Yend^2+Zend^2)- sqrt(Xinit^2+Yinit^2+Zinit^2);
        if abs(dis_error)<=0.2 
            b=1;  
        end
        theta1dot=thetadot(1,1);
        theta2dot=thetadot(2,1);
        theta3dot=thetadot(3,1);
        theta4dot=thetadot(4,1);
        theta5dot=thetadot(5,1);
        
        deltatheta1=radtodeg(theta1dot);
        deltatheta2=radtodeg(theta2dot);
        deltatheta3=radtodeg(theta3dot);
        deltatheta4=radtodeg(theta4dot);
        deltatheta5=radtodeg(theta5dot);
        deltatheta=[deltatheta1;deltatheta2;deltatheta3;deltatheta4;deltatheta5]
        pause(3);
    end 
    
end

function [Mdh] = DHmatrix(theta,d,a,alpha)
%DH-MATRIX 
%DH parameter
Mdh=[cosd(theta) -sind(theta)*cosd(alpha) sind(theta)*sind(alpha) a*cosd(theta);
     sind(theta) cosd(theta)*cosd(alpha)  -cosd(theta)*sind(alpha) a*sind(theta);
     0,sind(alpha),cosd(alpha),d;
     0,0,0,1];
end
