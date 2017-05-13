(TeX-add-style-hook
 "Nex_ex1"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("article" "oneside" "A4paper" "12pt")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("xeCJK" "slantfont" "boldfont") ("fncychap" "Lenny") ("rotating" "figuresright") ("ulem" "normalem")))
   (TeX-run-style-hooks
    "latex2e"
    "article"
    "art12"
    "xeCJK"
    "titlesec"
    "hyperref"
    "fncychap"
    "rotating"
    "capt-of"
    "amssymb"
    "ulem"
    "wrapfig"
    "grffile"
    "booktabs"
    "tabularx"
    "amsmath"
    "textcomp"
    "fancyhdr"
    "tikz"
    "longtable"
    "float"
    "geometry"
    "xunicode"
    "indentfirst"
    "fontspec"
    "listings"
    "xcolor")
   (LaTeX-add-labels
    "sec-1"
    "sec-1-1"
    "sec-1-2"
    "sec-2"
    "sec-3"
    "sec-3-1"
    "sec-3-2"
    "sec-3-3")))

