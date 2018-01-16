// ==UserScript==
// @name        posix-linker
// @namespace   https://github.com/osvein
// @description adds some missing links from XBD header pages to XSU function pages in the online POSIX standard viewer
// @include     http://pubs.opengroup.org/onlinepubs/9699919799/
// @version     1
// @grant       none
// ==/UserScript==

var frame = document.getElementById('main');
frame.addEventListener('load', function () {
	var re = /^https?:[/][/]pubs.opengroup.org[/]onlinepubs[/]9699919799[/]basedefs[/]\w+[.]h[.]html(#\w*)?$/;
	if (re.test(frame.contentWindow.location.href)) process(frame.contentDocument);
});

function process(doc) {
	doc.querySelectorAll('pre > tt').forEach(function (node, index, list) {
		node.innerHTML = node.innerHTML.replace(/ ([*]?)(\w+)[(]/gm, ' $1<a href="../functions/$2.html">$2</a>(');
	});
}
