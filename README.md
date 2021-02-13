# nl

> Plain text to HTML converter

## About

All this program does is convert plain text files into a more readable
form when embedded in HTML, i.e. it converts line breaks into `<br>`s.
My very simple use case is for filtering plain text README's in a
[cgit](https://git.zx2c4.com/cgit/about/) setup on __OpenBSD__.

## Installation

On __OpenBSD__ web applications are chrooted by default to `/var/www`.
Once you grab hold of this source you can just do `make install PREFIX=/var/www`.
A static binary will be thenceforth be available to all chrooted applications
at `/bin/nl`.