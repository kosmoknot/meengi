#!/bin/bash
echo Running tests:
echo
echo
echo 1.Checking template parser output

tempParser=$(diff ./TemplateTest.html ../site/TemplateTest.html -q)
echo $tempParser
if [[ -z $tempParser ]]; then
    echo "Template parser output matched!"
else
    echo "ERROR: Template parser output did not match!"
fi
