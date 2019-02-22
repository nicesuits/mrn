let component = ReasonReact.statelessComponent("IssueFilter");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      {ReasonReact.string("This is a placeholder for the issue filter.")}
    </div>,
};