/*
 *	Copyright 2016, Maxime Journaux <journaux.maxime@gmail.com>
 * 	This work is free. You can redistribute it and/or modify it under the
 *	terms of the Do What The Fuck You Want To Public License, Version 2,
 *	as published by Sam Hocevar. 
 *	See http://www.wtfpl.net for more details.
 */

#ifndef NODE_LED_MATRIX_H
#define NODE_LED_MATRIX_H

#include <node.h>
#include <node_object_wrap.h>
#include <nan.h>
#include <led-matrix.h>
#include <image.h>

using namespace rgb_matrix;
using rgb_matrix::GPIO;


/**
 * Class: LedMatrix
 *	Wrapper for rpi-rgb-led-matrix.
 */
class LedMatrix : public node::ObjectWrap {
	public:
		static Nan::Persistent<v8::Function> constructor;
		static void Init(v8::Local<v8::Object> exports);

		int GetWidth();
		int GetHeight();
		void SetPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);
		void Clear();
		void Fill(uint8_t r, uint8_t g, uint8_t b);
		void SetImage(Image* img);
		void Draw(int screenx, int screeny, int width, int height, int imgx, int imgy,
					bool looph, bool loopv);
		void Rotate(int angle);

	protected:
		LedMatrix(int rows = 16, int chained_displays = 1, int parallel_displays = 1, int brightness = 100, bool is64By64 = false);

		virtual ~LedMatrix();

		static void New(const Nan::FunctionCallbackInfo<v8::Value>& args);

		static void GetWidth(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void GetHeight(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void SetPixel(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void Clear(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void Fill(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void SetImageBuffer(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void Draw(const Nan::FunctionCallbackInfo<v8::Value>& args);
		static void Rotate(const Nan::FunctionCallbackInfo<V8::Value>& args);

	private:

		GPIO io;
		RGBMatrix* matrix;

		Image* image;
};

#endif