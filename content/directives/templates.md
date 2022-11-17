// $ChildList(ChildListItem) is a special template.It is used to render the grid.
// Each item in ChildList is rendered as ChildListItem(name). Where name is automatically taken as page name.

// DO NOT DELETE THESE ------>
# $ChildList(items)
<ul>$$items$$</ul>
#

# $ChildListItem(name)
<li><a href="$$name$$.html">$$name$$</a>
#
// DO NOT DELETE THESE <------

//Custom Templates for testing------>

# $Template0(arg1)
$$arg1$$ is part of the Template0. Just to be clear $$arg1$$ ISS A PART OF TEMPLATE0!!!
#

# $Template1(arg1,arg2)
$$arg1$$ and $$arg2$$ are part of the Template1
#

# $Template2():
This is Template2. It has zero arguments.
#

# $Template3()
Template3 is a multiline template;
with line1
line2
line3
#

# $Template4()
Template4 is using another template in it, $Template1(Rainbow,Sunshine)$
#

# $Template5()
Template5 is template with self referece, $Template5()$.
#

# $Template6();
Template 6 contains a cyclic dependence and so does $Template7()$.
#

# $Template7():
Template 7 contains a cyclic dependence and so does $Template6()$.
#

//<------Custom Templates for testing

# $Header(name):
<html>
#