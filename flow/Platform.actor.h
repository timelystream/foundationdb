/*
 * Platform.actor.h
 *
 * This source file is part of the FoundationDB open source project
 *
 * Copyright 2013-2022 Apple Inc. and the FoundationDB project authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

// When actually compiled (NO_INTELLISENSE), include the generated version of this file.  In intellisense use the source
// version.
#if defined(NO_INTELLISENSE) && !defined(FLOW_PLATFORM_ACTOR_G_H)
#define FLOW_PLATFORM_ACTOR_G_H
#include "flow/Platform.actor.g.h"
#elif !defined(FLOW_PLATFORM_ACTOR_H)
#define FLOW_PLATFORM_ACTOR_H

#include <stdlib.h>
#include <string>
#include <vector>

#include "flow/flow.h"
#include "flow/Platform.h"
#include "flow/actorcompiler.h" // This must be the last #include.
//

namespace platform {
// e.g. extension==".fdb", returns filenames relative to directory
Future<std::vector<std::string>> listFilesAsync(std::string const& directory, std::string const& extension = "");

// returns directory names relative to directory
Future<std::vector<std::string>> listDirectoriesAsync(std::string const& directory);

ACTOR Future<Void> findFilesRecursivelyAsync(std::string path, std::vector<std::string>* out);
} // namespace platform

#include "flow/unactorcompiler.h"
#endif
