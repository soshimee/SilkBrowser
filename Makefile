LDFLAGS := -lcurl `wx-config --cxxflags --libs base,xml,html,core,richtext,ribbon,aui`
CPPFLAGS:= `wx-config --cxxflags`

SilkBrowser: main.o
	c++ main.o -o SilkBrowser $(LDFLAGS)

run:
	./SilkBrowser

clean:
	rm *.o SilkBrowser
