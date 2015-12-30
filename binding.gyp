{
	"targets": [
		{
	        "target_name": "node-rpi-rgb-led-matrix",
	        "sources": [ "src/base.cc", "src/ledmatrix.cc" ],
	        "dependencies": [ "./binding.gyp:rpi-rgb-led-matrix" ],
	        "include_dirs": [ "./external/matrix/include", "./include/" ]
	    },
		{
			"target_name": "rpi-rgb-led-matrix",
			"type": "static_library",
			"sources": ["external/matrix/lib/bdf-font.cc",
				"external/matrix/lib/framebuffer.cc", "external/matrix/lib/gpio.cc",
				"external/matrix/lib/graphics.cc", "external/matrix/lib/led-matrix.cc",
				"external/matrix/lib/thread.cc", "external/matrix/lib/transformer.cc"],
			"libraries": ["-lrt", "-lm", "-lpthread"],
			"defines": ["ADAFRUIT_RGBMATRIX_HAT", "ADAFRUIT_RGBMATRIX_HAT_PWM", "RGB_SLOWDOWN_GPIO=1", "SHOW_REFRESH_RATE"],
			"include_dirs": [ "external/matrix/include" ],
	        "direct_dependent_settings": {
	            "include_dirs": [ "external/matrix/include" ]
	        }
		}
	]
}
