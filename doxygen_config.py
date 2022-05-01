# Configuration file for https://mcss.mosra.cz/documentation/doxygen/
DOXYFILE = "Doxyfile"
MAIN_PROJECT_URL = "https://github.com/zeldaret/tmc"
SHOW_UNDOCUMENTED = True
SEARCH_RESULT_ID_BYTES = 4
SEARCH_FILE_OFFSET_BYTES = 4
SEARCH_NAME_SIZE_BYTES = 2
SEARCH_DOWNLOAD_BINARY = True
HTML_HEADER = """
<style>
html {
    height: 100%;
}
dl {
    padding-left: 1em;
}
body {
    min-height: 100%;
    background-image:  url("../beanstalk-bg.png");
    background-attachment: fixed;
    background-size: cover;
}
body > header > nav {
    background: #2f363fe5;
}
main>article>.m-container {
    padding-top: 1em;
    padding-bottom: 1em;
    background: #2f363fe5;
}
code {
    background: #2f363fe5;
}
body > footer > nav {
    background: transparent;
    padding: 0;
    color: #555;
}
body > footer > nav a {
    color: #222;
}
ul.m-doc li.m-doc-expansible > a:first-child::before, ul.m-doc li.m-doc-collapsible > a:first-child::before {
    background: transparent;
}
.m-doc-template, dl.m-doc dd, ul.m-doc li > span.m-doc, dl.m-doc dd svg.m-math, ul.m-doc li > span.m-doc svg.m-math  {
    color: #a4a4a4;
}
img.m-image, svg.m-image {
    display: inline-block;
}
main p {
    text-indent: 0;
}
</style>
"""
LINKS_NAVBAR1 = [
    ("Modules", 'modules', []),
    ("Pages", 'pages', [])
]
LINKS_NAVBAR2 = [
    ("Classes", 'annotated', []),
    ("Files", 'files', [])
]