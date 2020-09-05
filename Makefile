LDFLAGS := -lcurl `wx-config --cxxflags --libs base,xml,html,core,richtext,ribbon,aui`
CPPFLAGS:= `wx-config --cxxflags` -DwxUSE_WEBVIEW_WEBKIT
OBJECTS:= main.o frame.o app.o

SilkBrowser: $(OBJECTS)
	c++ $(OBJECTS) -o SilkBrowser $(LDFLAGS)

run:
	./SilkBrowser

clean:
	rm *.o SilkBrowser
