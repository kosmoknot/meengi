//$ChildList() is a special template. Dont use it.

//Todo: Write Templates to support markdown style formatting here

//Custom Templates for testing

# $Template1(arg1,arg2)
$arg1 and $arg2 are part of the Template1
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
Template4 is using another template in it, $Template1(Rainbow,Sunshine)
#

# $Template5()
Template5 is template with self referece, $Template5() 
#

# $Template6();
Template 6 contains a cyclic dependence and so does $Template7();
#

# $Template7():
Template 7 contains a cyclic dependence and so does $Template6();
#