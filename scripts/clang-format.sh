#!/usr/bin/env bash

set -euo pipefail

mode="fix"
if [[ $# -gt 0 ]]; then
    case "$1" in
        --check|check)
            mode="check"
            shift
            ;;
        --fix|fix)
            shift
            ;;
    esac
fi

if ! command -v clang-format >/dev/null 2>&1; then
    echo "clang-format is required but was not found on PATH." >&2
    exit 1
fi

repo_root="$(git rev-parse --show-toplevel)"
cd "$repo_root"

should_format() {
    local file="$1"

    case "$file" in
        Dependencies/*|build/*)
            return 1
            ;;
        *.c|*.cc|*.cpp|*.cxx|*.h|*.hh|*.hpp|*.hxx)
            return 0
            ;;
        *)
            return 1
            ;;
    esac
}

declare -a files=()

if [[ $# -gt 0 ]]; then
    for file in "$@"; do
        if [[ -f "$file" ]] && should_format "$file"; then
            files+=("$file")
        fi
    done
else
    while IFS= read -r -d '' file; do
        if should_format "$file"; then
            files+=("$file")
        fi
    done < <(git ls-files -z -- '*.c' '*.cc' '*.cpp' '*.cxx' '*.h' '*.hh' '*.hpp' '*.hxx')
fi

if [[ ${#files[@]} -eq 0 ]]; then
    echo "No C/C++ source files matched clang-format."
    exit 0
fi

if [[ "$mode" == "check" ]]; then
    echo "Checking clang-format on ${#files[@]} file(s)..."
    for file in "${files[@]}"; do
        clang-format --dry-run --Werror "$file"
    done
    echo "clang-format check passed."
else
    echo "Formatting ${#files[@]} file(s) with clang-format..."
    for file in "${files[@]}"; do
        clang-format -i "$file"
    done
    echo "clang-format finished."
fi
