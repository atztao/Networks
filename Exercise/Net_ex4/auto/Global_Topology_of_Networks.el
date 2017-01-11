(TeX-add-style-hook
 "Global_Topology_of_Networks"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-class-options
                     '(("beamer" "bigger")))
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("inputenc" "utf8") ("fontenc" "T1") ("ulem" "normalem")))
   (TeX-run-style-hooks
    "latex2e"
    "beamer"
    "beamer10"
    "inputenc"
    "fontenc"
    "fixltx2e"
    "graphicx"
    "longtable"
    "float"
    "wrapfig"
    "rotating"
    "ulem"
    "amsmath"
    "textcomp"
    "marvosym"
    "wasysym"
    "amssymb"
    "hyperref"
    "minted"
    "xeCJK"
    "fontspec")
   (LaTeX-add-labels
    "fig:BoxplotFlowering")))

