environment = :development

http_path = "/"
css_dir = "css"
sass_dir = "sass"
images_dir = "img"

# Require any additional compass plugins installed on your system.
require 'breakpoint'
require 'susy'

output_style = (environment == :production) ? :expanded : :nested
relative_assets = true
line_comments = (environment == :production) ? false : true
sass_options = (environment == :production) ? {} : {:sourcemap => true}
