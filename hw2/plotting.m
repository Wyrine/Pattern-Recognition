m1 = [1 1.375];
m2 = [0.7 1.025];
sig1 = [1/30 1/60; 1/60 19/1200];
sig2 = [1/120 0; 0 11/1200];
in1 = inv(sig1);
in2 = inv(sig2);
clc
g1 = gmdistribution(m1, sig1);
g2 = gmdistribution(m2, sig2);
f1 = @(x,y) pdf(g1, [x y]);
f2 = @(x,y) pdf(g2, [x y]);
x = [0.85 1.15];
fcontour(f1, [0.5 1.5 0.7 1.8])
x1 = [0.8 0.9 1.2 1.1];
y1 = [1.2 1.4 1.4 1.5];
hold on
scatter(x1, y1)
x2 = [0.8 0.6 0.65 0.75];
y2 = [1.1 1 1.1 0.9];
scatter(x2, y2)
scatter(0.85, 1.15, 'filled')
fcontour(f2, [0.5 1.5 0.7 1.8])
hold off

                                                                                                                                                                                                              