clc
clear all
% ce petit code trace l'orbite d'un objet (La terre par exemple) autour
% d'un autre plus massif (le soleil par exemple) les données vient du code
% écrit en c++ et qui s'appelle problème_à_deux_corps.cpp

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Orbite de la terre autour du soleil par la méthode d'Euler Cromer
%
fid=fopen('data.txt','rb');
a=fscanf(fid,'%f%f');
fclose(fid);
t=a(1:5:length(a))
x=a(2:5:length(a))
y=a(3:5:length(a))
vx=a(4:5:length(a))
vy=a(5:5:length(a))
ccc=[0.1 0 -0.1 0 0.1];
cc=[0 0.1 0 -0.1 0];
figure
plot(x,y,'-r')
hold on
plot(ccc,cc,'-y')
xlabel('x')
ylabel('y')
title('L''orbite de la terre autour du soleil par la méthode d''Euler Cromer ')
legend('traj-terre','position du soleil')

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Orbite de la terre autour du soleil par la méthode d'Euler Richardson
%
fid=fopen('data2.txt','rb');
b=fscanf(fid,'%f%f');
fclose(fid);
t=b(1:5:length(b))
x=b(2:5:length(b))
y=b(3:5:length(b))
vx=b(4:5:length(b))
vy=b(5:5:length(b))
z=x*.0;
figure
plot(x,y,'-r')
hold on
plot(0,0,'oy','MarkerSize',30,'MarkerFaceColor','y')
hold on
plot(0.707,0.7072,'oy','MarkerSize',10,'MarkerFaceColor','b')
hold on
xlabel('x')
ylabel('y')
title('L''orbite de la terre autour du soleil d''Euler Richardson')
legend('traj-terre','Sun','Earth')


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Un mini-système solaire composé de deux planète, la terre et jupiter qui
% tourne autoure su soleil 
%
fid=fopen('data3.txt','rb');
c=fscanf(fid,'%f%f');
fclose(fid);
t=c(1:7:length(c))
x1=c(2:7:length(c))
y1=c(3:7:length(c))
vx1=c(4:7:length(c))
vy1=c(5:7:length(c))
x2=c(6:7:length(c))
y2=c(7:7:length(c))
figure
plot(x1,y1,'-r')
hold on
plot(x2,y2,'-b')
hold on
plot(0,0,'oy','MarkerSize',30,'MarkerFaceColor','y')
hold on
plot(0.707,0.7072,'oy','MarkerSize',10,'MarkerFaceColor','b')
hold on
plot(-2.489,4.577,'oy','MarkerSize',20,'MarkerFaceColor','r')
hold on
xlabel('Axe des abscises')
ylabel('Axe des ordonnées')
title('Mini-système solaire: Méthode d''Euler Richardson')
legend('traj.ter','traj.jupi','Sun','Earth','Jupiter')
