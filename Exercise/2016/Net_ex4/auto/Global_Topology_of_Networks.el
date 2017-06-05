(TeX-add-style-hook
 "Global_Topology_of_Networks"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("xeCJK" "SlantFont" "BoldFont") ("hyphenat" "none") ("overpic" "abs") ("fncychap" "Lenny") ("rotating" "figuresright") ("ulem" "normalem")))
   (TeX-run-style-hooks
    "latex2e"
    "beamer"
    "beamer10"
    "xeCJK"
    "hyphenat"
    "overpic"
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
    "fig:BoxplotFlowering")))

