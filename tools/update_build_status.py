#!/usr/bin/env python3
import json
import os
from datetime import datetime

sha1 = os.environ.get("SHA1", "")
ts = os.environ.get("TIMESTAMP")
if ts is None:
    ts = datetime.utcnow().strftime("%Y-%m-%dT%H:%M:%SZ")

status = {
    "lastBuild": ts,
    "success": True,
    "sha1": sha1,
    "errors": []
}

with open("build_status.json", "w", encoding="utf-8") as f:
    json.dump(status, f, indent=2)
