// $ChildList(ChildListItem) is a special template.It is used to render the grid.
// Each item in ChildList is rendered as ChildListItem(name). Where name is automatically taken as page name.

// DO NOT DELETE THESE ------>
# $ChildList(items)
<ul class="childlist">$$items$$</ul>
#

# $ChildListItem(name)
<li><a href="$$name$$.html"><figure><img style="width: 150px;" src="/links/images/$$name$$.gif"></figure>$$name$$<caption></caption></a>
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
<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <meta name="description" content="Meengi demo website">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1">
    <title>Meengi - $PageName()$ </title>
    <link rel="icon" href="/links/images/meengi.png" type="image/icon type">
    <link href="/links/style.css" rel="stylesheet" type="text/css" media="all">
</head>

<body>
#

# $Footer():
</body>
<footer>
    <div class="footerContainer">
        <div class="footer">
            <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">
                <img id="cc" alt="Creative Commons License" src="/links/images/creative_commons_min.webp" />
            </a>

            <a rel="meengi" href="https://github.com/kosmoknot/meengi">
                <img id="meengi" src="/links/images/meengi_light.png" />
            </a>

            <a rel="github" href="https://github.com/kosmoknot">
                <img id="git" src="/links//images/github.webp" />
            </a>

            <a rel="neocities" href="https://neocities.org/site/kosmoknot">
                <img id="neo" src="/links/images/neocities.webp" />
            </a>
        </div>
        <div class="footer_text">
            <p>KosmoKnot Ⓒ 2022 — BY-NC-SA 4.0</p>
        </div>
    </div>
</footer>

</html>
# 