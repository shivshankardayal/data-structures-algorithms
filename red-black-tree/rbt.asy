import geometry;

settings.outformat = "pdf";
//size(8cm, 0);

fill(circle((0, 0), 0.25cm), black);
fill(circle((-2cm, -2cm), 0.25cm), red);
fill(circle((2cm, -2cm), 0.25cm), red);
fill(circle((-3cm, -4cm), 0.25cm), black);
fill(circle((-1cm, -4cm), 0.25cm), black);
fill(circle((1cm, -4cm), 0.25cm), black);
fill(circle((3cm, -4cm), 0.25cm), black);
fill(circle((-3.5cm, -6cm), 0.25cm), black);
fill(circle((-2.5cm, -6cm), 0.25cm), black);
fill(circle((-1.5cm, -6cm), 0.25cm), black);
fill(circle((-.5cm, -6cm), 0.25cm), black);
fill(circle((1.5cm, -6cm), 0.25cm), black);
fill(circle((.5cm, -6cm), 0.25cm), black);
fill(circle((2.5cm, -5cm), 0.25cm), red);
fill(circle((3.5cm, -5cm), 0.25cm), red);
fill(circle((2cm, -7cm), 0.25cm), black);
fill(circle((3cm, -7cm), 0.25cm), black);
fill(circle((4cm, -7cm), 0.25cm), black);
fill(circle((5cm, -7cm), 0.25cm), black);

line l = line((0, 0), (-2cm, -2cm));
circle c = circle((point)(0, 0), 0.25cm);
point p[] = intersectionpoints(l, c);
circle d = circle((point)(-2cm, -2cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((0, 0), (2cm, -2cm));
point p[] = intersectionpoints(l, c);
d = circle((point)(2cm, -2cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-2cm, -2cm), (-3cm, -4cm));
circle c = circle((point)(-2cm, -2cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(-3cm, -4cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-2cm, -2cm), (-1cm, -4cm));
point p[] = intersectionpoints(l, c);
d = circle((point)(-1cm, -4cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-3cm, -4cm), (-3.5cm, -6cm));
circle c = circle((point)(-3cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(-3.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-3cm, -4cm), (-2.5cm, -6cm));
circle c = circle((point)(-3cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(-2.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-1cm, -4cm), (-1.5cm, -6cm));
circle c = circle((point)(-1cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(-1.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((-1cm, -4cm), (-.5cm, -6cm));
circle c = circle((point)(-1cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(-.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((2cm, -2cm), (1cm, -4cm));
c = circle((point)(2cm, -2cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(1cm, -4cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((2cm, -2cm), (3cm, -4cm));
c = circle((point)(2cm, -2cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(3cm, -4cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((1cm, -4cm), (.5cm, -6cm));
c = circle((point)(1cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((1cm, -4cm), (1.5cm, -6cm));
c = circle((point)(1cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(1.5cm, -6cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((3cm, -4cm), (2.5cm, -5cm));
c = circle((point)(3cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(2.5cm, -5cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((3cm, -4cm), (3.5cm, -5cm));
c = circle((point)(3cm, -4cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(3.5cm, -5cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((2.5cm, -5cm), (2cm, -7cm));
c = circle((point)(2.5cm, -5cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(2cm, -7cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((2.5cm, -5cm), (3cm, -7cm));
c = circle((point)(2.5cm, -5cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(3cm, -7cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((3.5cm, -5cm), (4cm, -7cm));
c = circle((point)(3.5cm, -5cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(4cm, -7cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

l = line((3.5cm, -5cm), (5cm, -7cm));
c = circle((point)(3.5cm, -5cm), 0.25cm);
point p[] = intersectionpoints(l, c);
d = circle((point)(5cm, -7cm), 0.25cm);
point q[] = intersectionpoints(l, d);

draw((p[0] -- q[1]), Arrow);

label("$4$", (0, 0), white);
label("$2$", (-2cm, -2cm), white);
label("$6$", (2cm, -2cm), white);
label("$1$", (-3cm, -4cm), white);
label("$3$", (-1cm, -4cm), white);
label("$5$", (1cm, -4cm), white);
label("$8$", (3cm, -4cm), white);
label("$7$", (2.5cm, -5cm), white);
label("$9$", (3.5cm, -5cm), white);
label("$N$", (-3.5cm, -6cm), white);
label("$N$", (-2.5cm, -6cm), white);
label("$N$", (-1.5cm, -6cm), white);
label("$N$", (-.5cm, -6cm), white);
label("$N$", (1.5cm, -6cm), white);
label("$N$", (.5cm, -6cm), white);
label("$N$", (2cm, -7cm), white);
label("$N$", (3cm, -7cm), white);
label("$N$", (4cm, -7cm), white);
label("$N$", (5cm, -7cm), white);
