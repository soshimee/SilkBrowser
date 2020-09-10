LDFLAGS := -lcurl `wx-config --cxxflags --libs base,xml,html,core,richtext,ribbon,aui,webview`
CPPFLAGS:= `wx-config --cxxflags` -fPIE
OBJECTS:= frame.o app.o

SilkBrowser: $(OBJECTS)
	c++ $(OBJECTS) -o SilkBrowser $(LDFLAGS)

run:
	./SilkBrowser

clean:
	rm *.o SilkBrowser
