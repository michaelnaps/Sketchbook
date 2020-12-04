clc;clear;

data = csvread("echo_data1.csv");
m = size(data);

p = polarplot(deg2rad(data(1,1)), data(1,2));
hold on
for i = 2:m(1)
    p.Marker = '.';
    p.MarkerSize = 10;
    p = polarplot(deg2rad(data(i,1)), data(i,2));
end
hold off