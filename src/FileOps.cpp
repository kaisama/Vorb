#include "stdafx.h"
#include "FileOps.h"

#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

bool vio::buildDirectoryTree(const Path& path, bool omitEnd /*= false*/) {
    if (!path.isNice()) return false;
    
    Path pa = path;
    if (omitEnd) {
        pa.trimEnd();
        if (pa.isNull()) return true; // Code successfully did nothing
    }

    fs::path bp(pa.getString());
    if (fs::exists(bp)) return true;
    return fs::create_directories(bp);
}
