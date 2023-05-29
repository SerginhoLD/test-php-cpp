#include <iostream>
#include <phpcpp.h>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

void sld_func()
{
    Php::out << "Hello PHP-CPP!" << std::endl;
}

class sld_opencv : public Php::Base {
private:
    Php::Value _path;
    cv::Mat _image;
public:
    /**
     *  C++ constructor and destructor
     */
    sld_opencv() = default;
    virtual ~sld_opencv() = default;

    void __construct(Php::Parameters &params)
    {
        _path = params[0];
    }

    Php::Value getPath()
    {
        return _path;
    }

    Php::Value getWidth()
    {
        _image = cv::imread(_path);
        return _image.size().height;
    }
};

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("sld", "1.0");

        // create namespace
        Php::Namespace space("SerginhoLD");

        // add sld_func() to namespace
        space.add<sld_func>("func");

        // description of the class so that PHP knows which methods are accessible,
        // the __construct method is private because PHP scripts are not allowed
        // to create Counter instances
        Php::Class<sld_opencv> sld_opencv_class("OpenCV");
        sld_opencv_class.method<&sld_opencv::__construct>("__construct");
        sld_opencv_class.method<&sld_opencv::getPath>("getPath");
        sld_opencv_class.method<&sld_opencv::getWidth>("getWidth");

        space.add(std::move(sld_opencv_class));

        // add namespace to extension
        extension.add(std::move(space));

        return extension;
    }
}
