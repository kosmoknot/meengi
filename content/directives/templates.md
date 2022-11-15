// $ChildList(ChildListItem) is a special template.It is used to render the grid.
// Each item in ChildList is rendered as ChildListItem(name). Where name is automatically taken as page name.
# $ChildList(items)
<ul>$$items$$</ul>
#

# $ChildListItem(name)
<li>$$name$$
#


//Custom Templates for testing

# $Template0(arg1)
$$arg1$$ is part of the Template0 <br>
#

# $Template1(arg1,arg2)
$$arg1$$ and $$arg2$$ are part of the Template1<br>
#

# $Template2():
This is Template2. It has zero arguments.<br>
#

# $Template3()
Template3 is a multiline template;<br>
with line1<br>
line2<br>
line3<br>
#

# $Template4()
Template4 is using another template in it, $Template1(Rainbow,Sunshine)$<br>
#

# $Template5()
Template5 is template with self referece, $Template5()$.<br>
#

# $Template6();
Template 6 contains a cyclic dependence and so does $Template7()$.<br>
#

# $Template7():
Template 7 contains a cyclic dependence and so does $Template6()$.<br>
#