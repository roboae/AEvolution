#include "pch.h"
#include "PyCore.h"

/*
* PyCore.cpp
* This file contains the definitions for the functions that bind the C++ classes to Python.
* The functions are called from PyLink.cpp.
* e.x. bindItem(m) is called from PyLink.cpp to bind the Item class to Python.
*
*
*/

void bindLayerEnum(py::module_& m)
{
    py::enum_<qualityOptions>(m, "Quality")
        .value("BEST", qualityOptions::BEST)
        .value("DRAFT", qualityOptions::DRAFT)
        .value("WIREFRAME", qualityOptions::WIREFRAME)
        .value("NONE", qualityOptions::NONE)
        .export_values();

    py::enum_<LayerFlag>(m, "LayerFlag")
        .value("VIDEO_ACTIVE", LayerFlag::VIDEO_ACTIVE)
        .value("AUDIO_ACTIVE", LayerFlag::AUDIO_ACTIVE)
        .value("EFFECTS_ACTIVE", LayerFlag::EFFECTS_ACTIVE)
        .value("MOTION_BLUR", LayerFlag::MOTION_BLUR)
        .value("FRAME_BLENDING", LayerFlag::FRAME_BLENDING)
        .value("LOCKED", LayerFlag::LOCKED)
        .value("SHY", LayerFlag::SHY)
        .value("COLLAPSE", LayerFlag::COLLAPSE)
        .value("AUTO_ORIENT_ROTATION", LayerFlag::AUTO_ORIENT_ROTATION)
        .value("ADJUSTMENT_LAYER", LayerFlag::ADJUSTMENT_LAYER)
        .value("TIME_REMAPPING", LayerFlag::TIME_REMAPPING)
        .value("LAYER_IS_3D", LayerFlag::LAYER_IS_3D)
        .value("LOOK_AT_CAMERA", LayerFlag::LOOK_AT_CAMERA)
        .value("LOOK_AT_POI", LayerFlag::LOOK_AT_POI)
        .value("SOLO", LayerFlag::SOLO)
        .value("MARKERS_LOCKED", LayerFlag::MARKERS_LOCKED)
        .value("NULL_LAYER", LayerFlag::NULL_LAYER)
        .value("HIDE_LOCKED_MASKS", LayerFlag::HIDE_LOCKED_MASKS)
        .value("GUIDE_LAYER", LayerFlag::GUIDE_LAYER)
        .value("ADVANCED_FRAME_BLENDING", LayerFlag::ADVANCED_FRAME_BLENDING)
        .value("SUBLAYERS_RENDER_SEPARATELY", LayerFlag::SUBLAYERS_RENDER_SEPARATELY)
        .value("ENVIRONMENT_LAYER", LayerFlag::ENVIRONMENT_LAYER)
        .export_values();
	
}


void bindLayer(py::module_& m)
{
    py::class_<Layer, std::shared_ptr<Layer>>(m, "Layer")
        .def(py::init<const std::string&>())
        .def_property("name", &Layer::GetLayerName, &Layer::SetLayerName)
        .def_property("quality", &Layer::getQuality, &Layer::setQuality)
        .def_property("startTime", &Layer::getOffset, &Layer::setOffset) //CHANGE IN DOCS -- wher the layer starts in comp time
        .def_property("index", &Layer::index, &Layer::changeIndex)
        .def_property("video_active", [](Layer& self) {return self.getFlag(LayerFlag::VIDEO_ACTIVE); },
            			[](Layer& self, bool value) {self.setFlag(LayerFlag::VIDEO_ACTIVE, value); })
        .def_property("audio_active", [](Layer& self) {return self.getFlag(LayerFlag::AUDIO_ACTIVE); },
            						[](Layer& self, bool value) {self.setFlag(LayerFlag::AUDIO_ACTIVE, value); })
        .def_property("effects_active", [](Layer& self) {return self.getFlag(LayerFlag::EFFECTS_ACTIVE); },
            									[](Layer& self, bool value) {self.setFlag(LayerFlag::EFFECTS_ACTIVE, value); })
        .def_property("motion_blur", [](Layer& self) {return self.getFlag(LayerFlag::MOTION_BLUR); },
            [](Layer& self, bool value) {self.setFlag(LayerFlag::MOTION_BLUR, value); })
        .def_property("frame_blending", [](Layer& self) {return self.getFlag(LayerFlag::FRAME_BLENDING); },
            			[](Layer& self, bool value) {self.setFlag(LayerFlag::FRAME_BLENDING, value); })
        .def_property("locked", [](Layer& self) {return self.getFlag(LayerFlag::LOCKED); },
            								[](Layer& self, bool value) {self.setFlag(LayerFlag::LOCKED, value); })
        .def_property("shy", [](Layer& self) {return self.getFlag(LayerFlag::SHY); },
            [](Layer& self, bool value) {self.setFlag(LayerFlag::SHY, value); })
        .def_property("collapse", [](Layer& self) {return self.getFlag(LayerFlag::COLLAPSE); },
            										[](Layer& self, bool value) {self.setFlag(LayerFlag::COLLAPSE, value); })
        .def_property("auto_orient_rotation", [](Layer& self) {return self.getFlag(LayerFlag::AUTO_ORIENT_ROTATION); },
            															[](Layer& self, bool value) {self.setFlag(LayerFlag::AUTO_ORIENT_ROTATION, value); })
        .def_property("adjustment_layer", [](Layer& self) {return self.getFlag(LayerFlag::ADJUSTMENT_LAYER); },
            			[](Layer& self, bool value) {self.setFlag(LayerFlag::ADJUSTMENT_LAYER, value); })
        .def_property("time_remapping", [](Layer& self) {return self.getFlag(LayerFlag::TIME_REMAPPING); },
            												[](Layer& self, bool value) {self.setFlag(LayerFlag::TIME_REMAPPING, value); })
        .def_property("layer_is_3d", [](Layer& self) {return self.getFlag(LayerFlag::LAYER_IS_3D); },
            [](Layer& self, bool value) {self.setFlag(LayerFlag::LAYER_IS_3D, value); })
        .def_property("look_at_camera", [](Layer& self) {return self.getFlag(LayerFlag::LOOK_AT_CAMERA); },
            															[](Layer& self, bool value) {self.setFlag(LayerFlag::LOOK_AT_CAMERA, value); })
        .def_property("look_at_poi", [](Layer& self) {return self.getFlag(LayerFlag::LOOK_AT_POI); },
            			[](Layer& self, bool value) {self.setFlag(LayerFlag::LOOK_AT_POI, value); })
        .def_property("solo", [](Layer& self) {return self.getFlag(LayerFlag::SOLO); },
            											[](Layer& self, bool value) {self.setFlag(LayerFlag::SOLO, value); })
        .def_property("markers_locked", [](Layer& self) {return self.getFlag(LayerFlag::MARKERS_LOCKED); },
            																[](Layer& self, bool value) {self.setFlag(LayerFlag::MARKERS_LOCKED, value); })
        .def_property("null_layer", [](Layer& self) {return self.getFlag(LayerFlag::NULL_LAYER); },
            				[](Layer& self, bool value) {self.setFlag(LayerFlag::NULL_LAYER, value); })
        .def_property("hide_locked_masks", [](Layer& self) {return self.getFlag(LayerFlag::HIDE_LOCKED_MASKS); },
            																			[](Layer& self, bool value) {self.setFlag(LayerFlag::HIDE_LOCKED_MASKS, value); })
        .def_property("guide_layer", [](Layer& self) {return self.getFlag(LayerFlag::GUIDE_LAYER); },
            				[](Layer& self, bool value) {self.setFlag(LayerFlag::GUIDE_LAYER, value); })
        .def_property("advanced_frame_blending", [](Layer& self) {return self.getFlag(LayerFlag::ADVANCED_FRAME_BLENDING); },
            																							[](Layer& self, bool value) {self.setFlag(LayerFlag::ADVANCED_FRAME_BLENDING, value); })
        .def_property("sublayers_render_separately", [](Layer& self) {return self.getFlag(LayerFlag::SUBLAYERS_RENDER_SEPARATELY); },
            																												[](Layer& self, bool value) {self.setFlag(LayerFlag::SUBLAYERS_RENDER_SEPARATELY, value); })
        .def_property("environment_layer", [](Layer& self) {return self.getFlag(LayerFlag::ENVIRONMENT_LAYER); },
            				[](Layer& self, bool value) {self.setFlag(LayerFlag::ENVIRONMENT_LAYER, value); })

        .def_property_readonly("sourceName", &Layer::GetSourceName)
        .def_property_readonly("time", &Layer::layerTime)  // layer in frame time
        .def_property_readonly("compTime", &Layer::layerCompTime) // layer in comp time AKA frame time
        .def_property_readonly("inPoint", &Layer::inPoint) 
        .def_property_readonly("compInPoint", &Layer::compInPoint) 
        .def_property_readonly("duration", &Layer::duration)
        .def_property_readonly("compDuration", &Layer::compDuration) 
        .def_property_readonly("source", &Layer::getSource)
        .def("delete", &Layer::deleteLayer) 
        .def("duplicate", &Layer::duplicate);
        
}

void bindLayerCollection(py::module_& m) {
    py::class_<LayerCollection, std::shared_ptr<LayerCollection>>(m, "LayerCollection")
        .def(py::init<const std::string&, std::vector<std::shared_ptr<Layer>>>()) // Updated constructor
        .def("__getitem__", [](const LayerCollection& c, size_t i) {
        if (i < 0 || i >= c.size()) throw py::index_error(); // Simplified range check
        return c[i];
            }) // Return Layer as reference
        .def("__setitem__", [](LayerCollection& c, size_t i, std::shared_ptr<Layer> l) {
                if (i >= c.size()) throw py::index_error();
                if (i < c.size()) {
                    c[i] = l; // Ensure c[i] is a std::shared_ptr<Layer>
                }
            })
        .def("__len__", [](const LayerCollection& c) { return c.size(); })
        .def("__iter__", [](const LayerCollection& c) {
        return py::make_iterator(c.begin(), c.end());
            }, py::keep_alive<0, 1>()) // Use const-qualified begin and end



           //define __str__ method, which gets the comp name for the collection
        .def("__str__", [](LayerCollection& c) {
            return c.getCompName();
            })

        .def("append", &LayerCollection::addLayerToCollection, py::arg("layer"), py::arg("index") = -1)
        .def("insert", &LayerCollection::addLayerToCollection, py::arg("layer"), py::arg("index"))
        .def("remove", &LayerCollection::removeLayerFromCollection, py::arg("layer"))
        .def("pop", &LayerCollection::RemoveLayerByIndex, py::arg("index") = -1)
        .def("getAllLayers", &LayerCollection::getAllLayers);

}

void bindSolidItem(py::module_& m)
{
    /*
    *std::string name, std::tuple<float, float> dimensions,
        std::tuple<float, float, float, float> rgba, float duration, int index);
    */
    py::class_<SolidItem, FootageItem, std::shared_ptr<SolidItem>>(m, "SolidItem")
        .def(py::init(&SolidItem::createNew), py::arg("name") = "New Solid", py::arg("dimensions") = std::make_tuple(1920, 1080),
            py::arg("rgba") = std::make_tuple(1, 1, 1, 1), py::arg("duration") = 10, py::arg("index") = -1);

}

void bindItem(py::module_& m)
{
    py::class_<Item, std::shared_ptr<Item>>(m, "Item")
        .def(py::init<const std::string&>())
        .def_property_readonly("width", &Item::getWidth)
        .def_property_readonly("height", &Item::getHeight)
        .def_property_readonly("duration", &Item::getDuration)
        .def_property("time", &Item::getCurrentTime, &Item::setCurrentTime)
        .def_property("selected", &Item::isSelected, &Item::setSelected)
        .def_property("name",
            &Item::getName,
            &Item::setName);
}

void bindItemCollection(py::module_& m) {
    py::class_<ItemCollection, std::shared_ptr<ItemCollection>>(m, "ItemCollection")
        .def(py::init<const std::string&>())
        .def("__getitem__", [](const ItemCollection& c, int i) {
            // Handle negative index
            size_t index = (i < 0) ? c.size() + i : i;

            if (index >= c.size()) throw py::index_error();
            return c[index];
                }) // Return Item as reference


        .def("__len__", [](const ItemCollection& c) { return c.size(); })
        .def("__iter__", [](const ItemCollection& c) {
        return py::make_iterator(c.begin(), c.end());
            }, py::keep_alive<0, 1>()) // Use const-qualified begin and end

        .def("append", &ItemCollection::append, py::arg("item"))
        .def("remove", &ItemCollection::remove, py::arg("item"));
}

void bindCompItem(py::module_& m)
{
    /*
    static CompItem CreateNew(std::string name, float width, float height, float frameRate, float duration, float aspectRatio) { */
    py::class_<CompItem, Item, std::shared_ptr<CompItem>>(m, "CompItem")
        .def(py::init(&CompItem::CreateNew),
            py::arg("name") = "New Comp",
            py::arg("width") = 1920,
            py::arg("height") = 1080,
            py::arg("frameRate") = 24.0,
            py::arg("duration") = 10,
            py::arg("aspectRatio") = 1.0)
        .def_property_readonly("layer", &CompItem::getLayers)
        .def_property_readonly("layers", &CompItem::getLayers)
        .def_property_readonly("selectedLayers", &CompItem::getSelectedLayers)
        .def_property_readonly("selectedLayer", &CompItem::getSelectedLayers)
        .def_property_readonly("numLayers", &CompItem::NumLayers)
        .def_property("width", &Item::getWidth, &CompItem::setWidth)
        .def_property("height", &Item::getHeight, &CompItem::setHeight)
        .def_property("duration", &CompItem::getDuration, &CompItem::setDuration)
        .def_property("time", &CompItem::getCurrentTime, &CompItem::setCurrentTime)
        .def_property("frameRate",//ADD TO DOCS
            &CompItem::getFrameRate,
            &CompItem::setFrameRate);
}

void bindFootageItem(py::module_& m)
{
    py::class_<FootageItem, Item, std::shared_ptr<FootageItem>>(m, "FootageItem")
        .def(py::init(&FootageItem::createNew), py::arg("name") = "New Layer", py::arg("path") = NULL, py::arg("index") = -1)
        .def_property_readonly("path", &FootageItem::getPath)
        .def("replace", &FootageItem::replaceWithNewSource, py::arg("name"), py::arg("path"));
}

void bindProjectCollection(py::module_& m) {
    py::class_<ProjectCollection, std::shared_ptr<ProjectCollection>>(m, "ProjectCollection")
        .def(py::init<const std::string&>())
        .def("__getitem__", [](const ProjectCollection& c, int i) {
            // Handle negative index by converting it to positive
            size_t index = (i < 0) ? c.size() + i : i;

            if (index >= c.size()) throw py::index_error();
            return c[index];
                }) // Return Item as reference

        .def("__len__", [](const ProjectCollection& c) { return c.size(); })
        .def("__iter__", [](const ProjectCollection& c) {
            return py::make_iterator(c.begin(), c.end());
            }, py::keep_alive<0, 1>()) // Use const-qualified begin and end

        .def("append", &ProjectCollection::append, py::arg("item"))
        .def("remove", &ProjectCollection::remove, py::arg("item"));

}

void bindFolderItem(py::module_& m)
{
    py::class_<FolderItem, Item, std::shared_ptr<FolderItem>>(m, "FolderItem")
        .def(py::init(&FolderItem::createNew), py::arg("name") = "New Folder")
        .def_property_readonly("children", &FolderItem::ChildItems);

}

void bindAdjustmentLayerItem(py::module_& m)
{
    py::class_<AdjustmentLayer, Layer, std::shared_ptr<AdjustmentLayer>>(m, "AdjustmentLayer")
        //takes compitem and name as args
        .def(py::init(&AdjustmentLayer::createNew), py::arg("comp"), py::arg("name") = "Adjustment Layer");
}

void bindProject(py::module_& m)
{
    py::class_<Project, std::shared_ptr<Project>>(m, "Project")
        .def(py::init<>())
        .def_property_readonly("activeItem", &Project::ActiveItem)
        .def_property_readonly("activeLayer", &Project::GetActiveLayer)
        .def_property_readonly("name", &Project::getName)
        .def_property_readonly("path", &Project::getPath)
        .def_property_readonly("items", &Project::ChildItems)
        .def_property_readonly("selectedItems", &Project::SelectedItems) //add to docs
        .def("saveAs", &Project::saveAs, py::arg("path"));

}

void bindApp(py::module_& m)
{

    py::class_<App, std::shared_ptr<App>>(m, "App")
        .def(py::init<>())
        .def_property_readonly("path", &App::pluginPaths)
        .def_property_readonly("project", &App::getProject)
        .def("beginUndoGroup", &App::beginUndoGroup, py::arg("undo_name") = "Default Undo Group Name")
        .def("endUndoGroup", &App::endUndoGroup)
        .def("reportInfo", [](App& self, py::object info) {
        std::string infoStr = py::str(info); // Convert any Python object to a string
        self.reportInfo(infoStr);
            }, py::arg("info"));

}

void bindManifest(py::module_& m)
{
    py::class_<Manifest>(m, "Manifest")
        .def(py::init<>())
        .def_readwrite("name", &Manifest::name)
        .def_readwrite("version", &Manifest::version)
        .def_readwrite("author", &Manifest::author)
        .def_readwrite("description", &Manifest::description)
        .def_readwrite("entry", &Manifest::entryPath)
        .def_readwrite("dependencies", &Manifest::dependenciesFolder);
}