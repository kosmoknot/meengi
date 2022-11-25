# Meengi(Memex Engine)

<p align="center">
<img src="/links/images/meengi.png" alt="drawing" style="" width="300"/>
</p>

## About ([Demo](https://meengi.netlify.app/site/index.html))
A memex and logs based journaling system meant to keep track of my life.

Still in early development.

Meengi uses a simple static website generator written in C++ that takes markdown files as input.


### Purpose
Created for my website [kosmoknot](https://kosmoknot.netlify.app/)

Other similar websites, which use similar tools, used for inspiration:
- [hundredrabbits/100r.co](https://github.com/hundredrabbits/100r.co)
- [abstractxan](https://abstractxan.xyz)

## Features

### Templates
A user defined reusable textblock. Templates can also accept inputs arguments, which make templates more flexible.

There are some special templates which can fetch some info like;

- Page Name: Fetches current page name.
- ChildList: Prints list of children pages organised under this page.
- NavigList: Shows navigation menu.
- TreeMap:   Shows tree map of the webisite.

### Layout
Layout.md file contains structure of the whole website.

Each page can contain links to children pages, these links are shown according to styling defined by childLinkList template.

## Usage
### Content
Contains actual content to be rendered on each html. Name of the html page will be same as the name of the .md file.

A file will not be rendered into a html page unless the filename is mentioned in the layout.md.

### Content / Directives
Contain layout.md and template.md files which define how content files are rendered.

### Links
Dedicated place to store images, gif, css and any other useful links. (If you feel like it you can rename/delete this folder)

### How to run?
Just launch meengi!

## Todo:
- Passing args from layout to modify rendering childlist
- add mastadon
