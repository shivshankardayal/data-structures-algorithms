input metagraph

beginfig(0)
	prologues := 2;
	noderadius:= 9;
	node.a("A"); node.b("B"); node.c("C"); node.d("D"); node.e("E");
	c.c = b.c + (2cm, 0);
	e.c = c.c + (2cm, 0);
	a.c = c.c - (1cm, 1cm);
	d.c = c.c + (1cm, -1cm);
	drawboxed(b, c, e, a, d);
	drawarrow arc(b)(--)(c);
	drawarrow arc(c)(--)(e);
	drawarrow arc(a)(--)(c);
	drawarrow arc(a)(--)(d);
	drawarrow arc(c)(--)(d);
	drawarrow arc (d)({dir (90)}..{dir (45)})(e);
	drawarrow arc (e)({dir (-90)}..{dir (225)})(d);
endfig;
\bye
