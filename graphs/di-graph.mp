input metagraph

beginfig(1)
	prologues := 3;
	noderadius:= 9;
	node.a("0"); node.b("1"); node.c("2"); node.d("3"); node.e("4");
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
endfig;
\bye
