if(!settings.multipleView) settings.batchView=false;
settings.tex="xelatex";
settings.inlinetex=true;
deletepreamble();
defaultfilename="binary_tree-1";
if(settings.render < 0) settings.render=4;
settings.outformat="";
settings.inlineimage=true;
settings.embed=true;
settings.toolbar=false;
viewportmargin=(2,2);

import fontsize;
unitsize(1cm);
defaultpen(fontsize(9pt));
import binarytree;

picture pic;

binarytree st=searchtree(10,5,2,1,3,4,7,6,8,9,15,13,12,11,14,17,16,18,19);
draw(pic, st, blue, condensed=true);
add(pic.fit(),(0,0),10S);
