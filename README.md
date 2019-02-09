md5-sha1-wasm
---------------

WebAssembly implemention of md5 and sha1

## Requirements

- Emscripten
  - [Emscripten SDK](https://kripken.github.io/emscripten-site/docs/tools_reference/emsdk.html)
  - `./emsdk install sdk-incoming-64bit`
- [Binaryen](https://github.com/WebAssembly/binaryen)

## Makefile

```
$ make
$ python -m SimpleHTTPServer 8000
```

## Usage
```
<script src="md5-sha1.js"></script>
<script>
  //���ɰ��������������
  const md5_hex = Module.cwrap('md5_hex','string',['string']);
  const md5_init = Module.cwrap('md5_init');
  const md5_update = Module.cwrap('md5_update',null,['string']);
  const md5_final = Module.cwrap('md5_final','string');
  const sha1_init = Module.cwrap('sha1_init');
  const sha1_update = Module.cwrap('sha1_update',null,['string']);
  const sha1_final = Module.cwrap('sha1_final','string');

  //����md5
  console.log(md5_hex('test'));

  //��������md5
  md5_init();
  md5_update('test');
  md5_update('test2');
  console.log(md5_final());

  //��������sha1
  sha1_init();
  sha1_update('test');
  sha1_update('test2');
  console.log(sha1_final());
</script>
```

Open URL <http://localhost:8000/bin/md5-sha1.html> in your browser.

## License
Public Domain
