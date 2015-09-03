require 'sass-globbing'
require 'breakpoint'
require 'susy'

environment = :development

# Location of the theme's resources.
css_dir         = "css"
sass_dir        = "sass"
images_dir      = "images"
javascripts_dir = "js"
fonts_dir       = "fonts"
relative_assets = true

output_style = (environment == :development) ? :expanded : :compressed
line_comments = (environment == :development) ? true : false
sass_options = {:sourcemap => true}
