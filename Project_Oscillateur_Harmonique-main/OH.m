clear all

%question 1 et 2
fid=fopen('data2.txt','rb');
a=fscanf(fid,'%f%f');
fclose(fid);
t=a(1:2:length(a))
tt=a(2:2:length(a))
figure
plot(tt,t,'-r')
xlabel('temps')
ylabel('delta E')
title('Methode d''Euler-Richardson')

%Methode d'Euler-Richardson
fidd=fopen('data1.txt','rb');
b=fscanf(fidd,'%f%f');
fclose(fidd);
t=b(1:2:length(b))
tt=b(2:2:length(b))
figure
plot(tt,t,'-r')
xlabel('temps')
ylabel('delta E')
title('Methode d''Euler')

%question4: OH et espace de phase 
fi=fopen('data3.txt','rb');
c=fscanf(fi,'%f%f');
fclose(fi);
xn=c(1:3:length(c))
vn=c(2:3:length(c))
tn=c(3:3:length(c))
figure
plot(xn,vn,'-g')
xlabel('position')
ylabel('vitesse')
title('Methode d''Euler pour trouver la position x(t)')

%figure
%plot(tn, vn, '-r')
%xlabel('temps')
%ylabel('vitesse v(t)')
%title('Methode d''Euler pour trouver la vitesse v(t)')

%question5: OH amortie
fd=fopen('data5.txt','rb');
a5=fscanf(fd,'%f%f');
fclose(fd);
t5=a5(1:3:length(a5))
tt5=a5(2:3:length(a5))
ttt5=a5(3:3:length(a5))
figure
plot(ttt5,t5,'-r')
xlabel('temps')
ylabel('position')
title('Methode d''E-R pour l''OH amortie')
figure
plot(ttt5,tt5,'-r')
xlabel('temps')
ylabel('vitesse')
title('Methode d''E-R pour l''OH amortie')

% question 6: système à force extérieure
fd6=fopen('data6.txt','rb');
a6=fscanf(fd6,'%f%f');
fclose(fd6);
t6=a6(1:3:length(a6))
tt6=a6(2:3:length(a6))
ttt6=a6(3:3:length(a6))
figure
plot(ttt6,t6,'-r')
xlabel('temps')
ylabel('position')
title('système à une force extérieure')
figure
plot(ttt6,tt6,'-r')
xlabel('temps')
ylabel('vitesse')
title('système à force extérieure')

